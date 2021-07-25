# docker build -t bd-c4g .
# docker run -p 1433:1433 --rm -it bd-c4g

FROM mcr.microsoft.com/mssql/server:2017-latest

RUN apt update

RUN apt install -y unixodbc-dev msodbcsql17 mssql-tools

RUN apt install -y python3-pip
RUN pip3 install flask flask_sqlalchemy pyodbc

ENV FLASK_APP=/BD/Application/C4G
ENV LC_ALL=C.UTF-8
ENV LANG=C.UTF-8

ENV FLASK_ENV=development
ENV SECRET_KEY='\xb6z\xee\x1d\xf0\x02o\xa6\xf5\xc7\x13*\xa9@\x00x\xae\x8f\xda$\r\x12\xbcf\xa9\xabP\xc0\x10\x80\xe3\xc7'

ENV SA_PASSWORD=Password123
ENV ACCEPT_EULA=Y

ADD SQL /BD/SQL

RUN /opt/mssql/bin/sqlservr --accept-eula >/dev/null & (sleep 15 && /opt/mssql-tools/bin/sqlcmd -S localhost -U SA -P ${SA_PASSWORD} -i /BD/SQL/create_database.sql >/dev/null)

ADD Application /BD/Application

#CMD nohup /opt/mssql/bin/sqlservr >/dev/null 2>&1 & nohup flask run --host 0.0.0.0
CMD nohup /opt/mssql/bin/sqlservr >/dev/null 2>&1 & python3 /BD/Application/C4G.py
