# docker build -t bd .
# docker run -p 1433:1433 --rm -it bd

FROM microsoft/mssql-server-linux

ADD SQL /mnt/SQL

ENV ACCEPT_EULA=Y
ENV SA_PASSWORD=Password123
ENV MSSQL_PID=Developer
ENV MSSQL_TCP_PORT=1433

RUN /opt/mssql/bin/sqlservr --accept-eula & (sleep 15 && /opt/mssql-tools/bin/sqlcmd -S localhost -U SA -P ${SA_PASSWORD} -i /mnt/SQL/create_database.sql)

CMD /opt/mssql/bin/sqlservr
