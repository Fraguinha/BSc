# Libraries
import datetime
import os

from flask import (Flask, flash, redirect, render_template, request, session,
                   url_for)
from sqlalchemy import MetaData, Table, create_engine, engine, exists
from sqlalchemy.dialects.mssql import pyodbc
from sqlalchemy.engine import Connection, ResultProxy, RowProxy

# Variables

USER = 'SA'
PASSWORD = os.environ.get('SA_PASSWORD')

HOST = 'localhost'
PORT = '1433'

DATABASE = 'C4G'

URL = 'mssql+pyodbc://' + USER + ':' + PASSWORD + \
    '@' + HOST + ':' + PORT + '/' + DATABASE + \
    '?driver=ODBC+Driver+17+for+SQL+Server'

# Flask

app = Flask(__name__)
app.secret_key = os.environ.get('SECRET_KEY')

# Database
engine = create_engine(URL, convert_unicode=True)  # type: Engine
metadata = MetaData(bind=engine)  # type: Table
connection = engine.connect()  # type: Connection


@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'GET':
        res = connection.execute(
            'SELECT * FROM _Resource;'
        ).fetchall()
        srv = connection.execute(
            'SELECT * FROM _Service;'
        ).fetchall()
        return render_template('index.html', resources=res, services=srv)
    elif request.method == 'POST':
        if session.get('username'):
            if request.form['method'] == 'service':
                now = datetime.datetime.now()
                start = datetime.datetime.strptime(
                    request.form['start'], "%Y-%m-%d")
                end = datetime.datetime.strptime(
                    request.form['end'], "%Y-%m-%d")
                if end - start >= datetime.timedelta(0):
                    try:
                        result = connection.execute(
                            'INSERT INTO _Service_Requisition ([Username], [ServiceID], [Date_Start], [Date_End]) VALUES (?, ?, ?, ?);',
                            (session['username'], request.form['service'],
                             request.form['start'], request.form['end'])
                        )
                        flash('Service required', 'success')
                        return redirect(url_for('index'))
                    except:
                        flash('Service already required', 'error')
                        return redirect(url_for('index'))
                else:
                    flash('Invalid time', 'error')
                    return redirect(url_for('index'))
            elif request.form['method'] == 'resource':
                now = datetime.datetime.now()
                start = datetime.datetime.strptime(
                    request.form['start'], "%Y-%m-%d")
                end = datetime.datetime.strptime(
                    request.form['end'], "%Y-%m-%d")
                if end - start >= datetime.timedelta(0):
                    count = connection.execute(
                        'SELECT SUM(Quantity) AS S FROM _Resource_Allocation WHERE ResourceID = ?;',
                        (request.form['resource'])
                    ).first()
                    count_used = connection.execute(
                        'SELECT COUNT(ResourceID) AS C FROM _Resource_Requisition WHERE Date_Start >= ? AND Date_Start <= ? AND Date_End >= ? AND Date_End <= ?;',
                        (request.form['start'], request.form['end'],
                         request.form['start'], request.form['end'])
                    ).first()
                    if count.S - count_used.C >= int(request.form['quantity']):
                        try:
                            result = connection.execute(
                                'INSERT INTO _Resource_Requisition ([Username], [ResourceID], [Quantity], [Date_Start], [Date_End]) VALUES (?, ?, ?, ?, ?);',
                                (session['username'], request.form['resource'], request.form['quantity'],
                                 request.form['start'], request.form['end'])
                            )
                            flash('Resource required', 'success')
                            return redirect(url_for('index'))
                        except:
                            flash('Resource already required', 'error')
                            return redirect(url_for('index'))
                    else:
                        flash('Resource unavailable', 'error')
                        return redirect(url_for('index'))
                else:
                    flash('Invalid time', 'error')
                    return redirect(url_for('index'))
        else:
            flash('you must be logged in', 'error')
            return redirect(url_for('index'))


@app.route('/Entity')
def entity():
    if session.get('admin'):
        ent = ['Institution',  'Laboratory', 'Workgroup', 'Resource', 'Service',
               'Member', 'Resource_requisition', 'Service_requisition', 'Admin', 'User']
    else:
        ent = ['Institution', 'Laboratory', 'Workgroup', 'Member', 'Resource', 'Service',
               'Resource_requisition', 'Service_requisition']
    return render_template('entity.html', entities=ent)


@app.route('/Institution', methods=['GET', 'POST'])
def institution():
    if request.method == 'GET':
        ist = connection.execute(
            'SELECT * FROM _Institution;'
        ).fetchall()
        return render_template('institution.html', institutions=ist)
    elif request.method == 'POST':
        if session.get('admin'):
            if request.form['method'] == 'add':
                try:
                    result = connection.execute(
                        'INSERT INTO _Institution ([Name], [Email]) VALUES (?, ?);',
                        (request.form['name'], request.form['email'])
                    )
                    flash('Institution added', 'success')
                    return redirect(url_for('institution'))
                except:
                    flash('Institution already added', 'error')
                    return redirect(url_for('institution'))
            elif request.form['method'] == 'update':
                result = connection.execute(
                    'UPDATE _Institution SET Name = ?, Email = ? WHERE InstitutionID = ?;',
                    (request.form['name'], request.form['email'],
                     request.form['id'])
                )
                flash('Institution updated', 'success')
                return redirect(url_for('institution'))
            elif request.form['method'] == 'delete':
                try:
                    result = connection.execute(
                        'DELETE FROM _Institution WHERE InstitutionID = ?;',
                        (request.form['id'])
                    )
                    flash('Institution deleted', 'success')
                    return redirect(url_for('institution'))
                except:
                    flash('Institution has laboratories', 'error')
                    return redirect(url_for('institution'))
        else:
            return redirect(url_for('login'))


@app.route('/Laboratory', methods=['GET', 'POST'])
def laboratory():
    if request.method == 'GET':
        lab = connection.execute(
            'SELECT * FROM _Laboratory;'
        ).fetchall()
        ist = connection.execute(
            'SELECT * FROM _Institution;'
        ).fetchall()
        res = connection.execute(
            'SELECT * FROM _Resource;'
        ).fetchall()
        alc = connection.execute(
            'SELECT LaboratoryID, _Resource.ResourceID, Name, Quantity FROM _Resource, _Resource_Allocation WHERE _Resource.ResourceID = _Resource_Allocation.ResourceID;'
        ).fetchall()
        return render_template('laboratory.html', laboratories=lab, institutions=ist, resources=res, allocations=alc)
    elif request.method == 'POST':
        if session.get('admin'):
            if request.form['method'] == 'add':
                try:
                    result = connection.execute(
                        'INSERT INTO _Laboratory ([Name], [Email], [InstitutionID]) VALUES (?, ?, ?);',
                        (request.form['name'], request.form['email'],
                         request.form['institution'])
                    )
                    flash('Laboratory added', 'success')
                    return redirect(url_for('laboratory'))
                except:
                    flash('Laboratory already added', 'error')
                    return redirect(url_for('laboratory'))
            elif request.form['method'] == 'update':
                result = connection.execute(
                    'UPDATE _Laboratory SET Name = ?, Email = ?, InstitutionID = ? WHERE LaboratoryID = ?;',
                    (request.form['name'], request.form['email'],
                     request.form['institution'], request.form['id'])
                )
                flash('laboratory updated', 'success')
                return redirect(url_for('laboratory'))
            elif request.form['method'] == 'delete':
                try:
                    result = connection.execute(
                        'DELETE FROM _Laboratory WHERE LaboratoryID = ?;',
                        (request.form['id'])
                    )
                    flash('Laboratory deleted', 'success')
                    return redirect(url_for('laboratory'))
                except:
                    flash('Laboratory has workgroups or resources', 'error')
                    return redirect(url_for('laboratory'))
            elif request.form['method'] == 'allocate':
                result = connection.execute(
                    'SELECT * FROM _Resource_Allocation WHERE LaboratoryID = ? AND ResourceID = ?',
                    (request.form['id'], request.form['allocation'])
                ).first()
                if not result:
                    try:
                        result = connection.execute(
                            'INSERT INTO _Resource_Allocation ([Quantity], [LaboratoryID], [ResourceID]) VALUES (?, ?, ?);',
                            (request.form['quantity'], request.form['id'],
                             request.form['allocation'])
                        )
                        flash('Resource allocated', 'success')
                        return redirect(url_for('laboratory'))
                    except:
                        flash('Resource already allocated', 'error')
                        return redirect(url_for('laboratory'))
                else:
                    flash('An allocation for this resource already exists', 'error')
                    return redirect(url_for('laboratory'))
            elif request.form['method'] == 'deallocate':
                result = connection.execute(
                    'DELETE FROM _Resource_Allocation WHERE LaboratoryID = ? AND ResourceID = ?',
                    (request.form['id'], request.form['allocation'])
                )
                flash('Resource deallocated', 'success')
                return redirect(url_for('laboratory'))
        else:
            return redirect(url_for('login'))


@app.route('/Workgroup', methods=['GET', 'POST'])
def workgroup():
    if request.method == 'GET':
        wrk = connection.execute(
            'SELECT * FROM _Workgroup;'
        ).fetchall()
        lab = connection.execute(
            'SELECT * FROM _Laboratory;'
        ).fetchall()
        srv = connection.execute(
            'SELECT * FROM _Service;'
        ).fetchall()
        alc = connection.execute(
            'SELECT WorkgroupID, _Service.ServiceID, Name FROM _Service, _Service_Allocation WHERE _Service.ServiceID = _Service_Allocation.ServiceID;'
        ).fetchall()
        return render_template('workgroup.html', workgroups=wrk, laboratories=lab, services=srv, allocations=alc)
    elif request.method == 'POST':
        if session.get('admin'):
            if request.form['method'] == 'add':
                try:
                    result = connection.execute(
                        'INSERT INTO _Workgroup ([Name], [Email], [LaboratoryID]) VALUES (?, ?, ?);',
                        (request.form['name'], request.form['email'],
                         request.form['laboratory'])
                    )
                    flash('Workgroup added', 'success')
                    return redirect(url_for('workgroup'))
                except:
                    flash('Workgroup already added', 'error')
                    return redirect(url_for('workgroup'))
            elif request.form['method'] == 'update':
                result = connection.execute(
                    'UPDATE _Workgroup SET Name = ?, Email = ?, LaboratoryID = ? WHERE WorkgroupID = ?;',
                    (request.form['name'], request.form['email'],
                     request.form['laboratory'], request.form['id'])
                )
                flash('Workgroup updated', 'success')
                return redirect(url_for('workgroup'))
            elif request.form['method'] == 'delete':
                try:
                    result = connection.execute(
                        'DELETE FROM _Workgroup WHERE WorkgroupID = ?;',
                        (request.form['id'])
                    )
                    flash('workgroup deleted', 'success')
                    return redirect(url_for('workgroup'))
                except:
                    flash('workgroup has services', 'error')
                    return redirect(url_for('workgroup'))
            elif request.form['method'] == 'allocate':
                result = connection.execute(
                    'SELECT * FROM _Service_Allocation WHERE WorkgroupID = ? AND ServiceID = ?',
                    (request.form['id'], request.form['allocation'])
                ).first()
                if not result:
                    try:
                        result = connection.execute(
                            'INSERT INTO _Service_Allocation ([WorkgroupID], [ServiceID]) VALUES (?, ?);',
                            (request.form['id'], request.form['allocation'])
                        )
                        flash('service allocated', 'success')
                        return redirect(url_for('workgroup'))
                    except:
                        flash('service already allocated', 'error')
                        return redirect(url_for('workgroup'))
                else:
                    flash('An allocation for this service already exists', 'error')
                    return redirect(url_for('workgroup'))
            elif request.form['method'] == 'deallocate':
                result = connection.execute(
                    'DELETE FROM _Service_Allocation WHERE WorkgroupID = ? AND ServiceID = ?',
                    (request.form['id'], request.form['allocation'])
                )
                flash('Service deallocated', 'success')
                return redirect(url_for('workgroup'))
        else:
            return redirect(url_for('login'))


@app.route('/Resource', methods=['GET', 'POST'])
def resource():
    if request.method == 'GET':
        res = connection.execute(
            'SELECT * FROM _Resource;'
        ).fetchall()
        return render_template('resource.html', resources=res)
    elif request.method == 'POST':
        if session.get('admin'):
            if request.form['method'] == 'add':
                try:
                    result = connection.execute(
                        'INSERT INTO _Resource ([Name], [Description]) VALUES (?, ?);',
                        (request.form['name'], request.form['description'])
                    )
                    flash('Resource added', 'success')
                    return redirect(url_for('resource'))
                except:
                    flash('Resource already added', 'error')
                    return redirect(url_for('resource'))
            elif request.form['method'] == 'update':
                result = connection.execute(
                    'UPDATE _Resource SET Name = ?, Description = ? WHERE ResourceID = ?;',
                    (request.form['name'], request.form['description'],
                     request.form['id'])
                )
                flash('Resource updated', 'success')
                return redirect(url_for('resource'))
            elif request.form['method'] == 'delete':
                try:
                    result = connection.execute(
                        'DELETE FROM _Resource WHERE ResourceID = ?;',
                        (request.form['id'])
                    )
                    flash('Resource deleted', 'success')
                    return redirect(url_for('resource'))
                except:
                    flash('Resource is in use', 'error')
                    return redirect(url_for('resource'))
        else:
            return redirect(url_for('login'))


@app.route('/Service', methods=['GET', 'POST'])
def service():
    if request.method == 'GET':
        srv = connection.execute(
            'SELECT * FROM _Service;'
        ).fetchall()
        mbr = connection.execute(
            'SELECT * FROM _Member;'
        ).fetchall()
        res = connection.execute(
            'SELECT * FROM _Resource;'
        ).fetchall()
        dep = connection.execute(
            'SELECT ServiceID, _Resource.ResourceID, Name FROM _Dependency, _Resource WHERE _Dependency.ResourceID = _Resource.ResourceID;'
        ).fetchall()
        return render_template('service.html', services=srv, members=mbr, resources=res, dependencies=dep)
    elif request.method == 'POST':
        if session.get('admin'):
            if request.form['method'] == 'add':
                try:
                    result = connection.execute(
                        'INSERT INTO _Service ([Name], [Description], [MemberID]) VALUES (?, ?, ?);',
                        (request.form['name'], request.form['description'],
                         request.form['member'])
                    )
                    flash('Service added', 'success')
                    return redirect(url_for('service'))
                except:
                    flash('Service already added', 'error')
                    return redirect(url_for('service'))
            elif request.form['method'] == 'update':
                result = connection.execute(
                    'UPDATE _Service SET Name = ?, Description = ?, MemberID = ? WHERE ServiceID = ?;',
                    (request.form['name'], request.form['description'],
                     request.form['member'], request.form['id'])
                )
                flash('Service updated', 'success')
                return redirect(url_for('service'))
            elif request.form['method'] == 'delete':
                try:
                    result = connection.execute(
                        'DELETE FROM _Service WHERE ServiceID = ?;',
                        (request.form['id'])
                    )
                    flash('Service deleted', 'success')
                    return redirect(url_for('service'))
                except:
                    flash('Service in use or has dependencies', 'error')
                    return redirect(url_for('service'))
            elif request.form['method'] == 'allocate':
                result = connection.execute(
                    'SELECT * FROM _Dependency WHERE ServiceID = ? AND ResourceID = ?',
                    (request.form['id'], request.form['allocation'])
                ).first()
                if not result:
                    result = connection.execute(
                        'INSERT INTO _Dependency ([ServiceID], [ResourceID]) VALUES (?, ?);',
                        (request.form['id'], request.form['allocation'])
                    )
                    flash('Dependency created', 'success')
                    return redirect(url_for('service'))
                else:
                    flash('Dependency already exists', 'error')
                    return redirect(url_for('service'))
            elif request.form['method'] == 'deallocate':
                result = connection.execute(
                    'DELETE FROM _Dependency WHERE ServiceID = ? AND ResourceID = ?',
                    (request.form['id'], request.form['allocation'])
                )
                flash('Dependency removed', 'success')
                return redirect(url_for('service'))
        else:
            return redirect(url_for('login'))


@app.route('/Member', methods=['GET', 'POST'])
def member():
    if request.method == 'GET':
        mbr = connection.execute(
            'SELECT * FROM _Member;'
        ).fetchall()
        return render_template('member.html', members=mbr)
    elif request.method == 'POST':
        if session.get('admin'):
            if request.form['method'] == 'add':
                try:
                    result = connection.execute(
                        'INSERT INTO _Member ([Name], [Email]) VALUES (?, ?);',
                        (request.form['name'], request.form['email'])
                    )
                    flash('Member added', 'success')
                    return redirect(url_for('member'))
                except:
                    flash('Member already added', 'error')
                    return redirect(url_for('member'))
            elif request.form['method'] == 'update':
                result = connection.execute(
                    'UPDATE _Member SET Name = ?, Email = ? WHERE MemberID = ?;',
                    (request.form['name'], request.form['email'],
                     request.form['id'])
                )
                flash('Member updated', 'success')
                return redirect(url_for('member'))
            elif request.form['method'] == 'delete':
                try:
                    result = connection.execute(
                        'DELETE FROM _Member WHERE MemberID = ?;',
                        (request.form['id'])
                    )
                    flash('Member deleted', 'success')
                    return redirect(url_for('member'))
                except:
                    flash('Member has services', 'error')
                    return redirect(url_for('member'))
        else:
            return redirect(url_for('login'))


@app.route('/Resource_requisition', methods=['GET', 'POST'])
def resource_requisition():
    if request.method == 'GET':
        res_req = connection.execute(
            'SELECT * FROM _Resource_Requisition;'
        ).fetchall()
        res = connection.execute(
            'SELECT * FROM _Resource;'
        ).fetchall()
        return render_template('resource_requisition.html', requisitions=res_req, resources=res)
    elif request.method == 'POST':
        if request.form['method'] == 'delete':
            result = connection.execute(
                'DELETE FROM _Resource_Requisition WHERE Username = ? AND ResourceID = ? AND Quantity = ? AND Date_Start = ? AND Date_End = ?;',
                (request.form['username'], request.form['id'], request.form['quantity'],
                    request.form['start'], request.form['end'])
            )
            flash('Requisition deleted', 'success')
            return redirect(url_for('resource_requisition'))


@app.route('/Service_requisition', methods=['GET', 'POST'])
def service_requisition():
    if request.method == 'GET':
        srv_req = connection.execute(
            'SELECT * FROM _Service_Requisition;'
        ).fetchall()
        srv = connection.execute(
            'SELECT * FROM _Service;'
        ).fetchall()
        return render_template('service_requisition.html', requisitions=srv_req, services=srv)
    elif request.method == 'POST':
        if request.form['method'] == 'delete':
            result = connection.execute(
                'DELETE FROM _Service_Requisition WHERE Username = ? AND ServiceID = ? AND Date_Start = ? AND Date_End = ?;',
                (request.form['username'], request.form['id'],
                    request.form['start'], request.form['end'])
            )
            flash('Requisition deleted', 'success')
            return redirect(url_for('service_requisition'))


@app.route('/Admin', methods=['GET', 'POST'])
def admin():
    if session.get('admin'):
        if request.method == 'GET':
            adm = connection.execute(
                'SELECT * FROM _Admin;'
            ).fetchall()
            usr = connection.execute(
                'SELECT * FROM _User WHERE Username NOT IN (SELECT * FROM _ADMIN);'
            ).fetchall()
            return render_template('admin.html', admins=adm, users=usr)
        elif request.method == 'POST':
            if request.form['method'] == 'add':
                try:
                    result = connection.execute(
                        'INSERT INTO _Admin ([Username]) VALUES (?);',
                        (request.form['username'])
                    )
                    flash('Admin added', 'success')
                    return redirect(url_for('admin'))
                except:
                    flash('Admin already added', 'error')
                    return redirect(url_for('admin'))
            elif request.form['method'] == 'delete':
                result = connection.execute(
                    'DELETE FROM _Admin WHERE Username = ?;',
                    (request.form['id'])
                )
                flash('Admin deleted', 'success')
                return redirect(url_for('admin'))
    else:
        return redirect(url_for('login'))


@app.route('/User', methods=['GET', 'POST'])
def user():
    if session.get('admin'):
        if request.method == 'GET':
            usr = connection.execute(
                'SELECT * FROM _User;'
            ).fetchall()
            return render_template('user.html', users=usr)
        elif request.method == 'POST':
            if request.form['method'] == 'add':
                try:
                    result = connection.execute(
                        'INSERT INTO _User ([Username], [Password]) VALUES (?, ?);',
                        (request.form['username'], request.form['password'])
                    )
                    flash('User added', 'success')
                    return redirect(url_for('user'))
                except:
                    flash('User already added', 'error')
                    return redirect(url_for('user'))
            elif request.form['method'] == 'update':
                result = connection.execute(
                    'UPDATE _User SET Username = ?, Password = ? WHERE Username = ?;',
                    (request.form['username'], request.form['password'],
                     request.form['id'])
                )
                flash('User updated', 'success')
                return redirect(url_for('user'))
            elif request.form['method'] == 'delete':
                try:
                    result = connection.execute(
                        'DELETE FROM _User WHERE Username = ?;',
                        (request.form['id'])
                    )
                    flash('User deleted', 'success')
                    return redirect(url_for('user'))
                except:
                    flash('User is admin or has requests', 'error')
                    return redirect(url_for('user'))
    else:
        return redirect(url_for('login'))


@app.route('/Register', methods=['GET', 'POST'])
def register():
    if request.method == 'GET':
        return render_template('register.html')
    elif request.method == 'POST':
        result = connection.execute(
            'SELECT * FROM _User WHERE Username = ?',
            (request.form['username'])
        ).first()  # type: RowProxy
        if not result:
            result = connection.execute(
                'INSERT INTO _User ([Username], [Password]) VALUES (?, ?);',
                (request.form['username'], request.form['password'])
            )
            flash('You are now registered', 'success')
            return redirect(url_for('index'))
        flash('Username already taken', 'success')
        return redirect(url_for('register'))


@app.route('/Login', methods=['GET', 'POST'])
def login():
    if request.method == 'GET':
        if session.get('username'):
            flash('You are already logged in', 'success')
            return redirect(url_for('index'))
        return render_template('login.html')
    elif request.method == 'POST':
        result = connection.execute(
            'SELECT * FROM _User WHERE Username = ?',
            (request.form['username'])
        ).first()  # type: RowProxy
        if result:
            attributes = result.values()
            if request.form['username'] == attributes[0] and request.form['password'] == attributes[1]:
                flash('You are now logged in', 'success')
                session['username'] = request.form['username']
                result = connection.execute(
                    'SELECT * FROM _Admin WHERE Username = ?',
                    (request.form['username'])
                ).first()
                if result:
                    session['admin'] = True
                return redirect(url_for('index'))
        flash('Invalid Username/Password', 'success')
        return redirect(url_for('login'))


@app.route('/Logout')
def logout():
    if session.get('username'):
        session.clear()
        flash('You are now logged out', 'success')
    else:
        flash('You are already logged out', 'success')
    return redirect(url_for('index'))


if __name__ == '__main__':
    app.run(host='0.0.0.0', debug=True)
