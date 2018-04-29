-VER FECHAS EN OTROS FORMATOS
select codpro, codpie, cantidad, to_char(fecha,' "Granada", day dd "de" month "de" yyyy') from ventas;
select codpro, codpie, cantidad, to_char(fecha,' "Granada", day dd "de" month "de" yyyy') from ventas where to_char(fecha, 'yyyy')='2015';
select codpro, codpie, cantidad, to_char(fecha,' "Granada", day dd "de" month "de" yyyy') from ventas where to_char(fecha, 'yyyy')='2015' and to_char(fecha,'mm')='04';
--INSERTAR UNA FECHA INFERIOR CON EL AÑO INFERIOR A 2000
insert into ventas values('S2','P5','J1',150,to_date('18/09/1992','dd/mm/yyyy'));
select * from ventas;
--USAR SELECT COMO CALCULADORA
select 2435*0.7/432 from dual;
--MOSTRAR FECHA ACTUAL
select sysdate from dual;
select time from dual;
--el dia que era en una fecha
select to_char(to_date('17/02/1967','dd/mm/yyyy'),'day') from dual;
--UNION
select ciudad from proveedor union select ciudad from pieza;
--select codpro from proveedor intersect select codpie from pieza;
select codpro from proveedor minus select codpie from pieza;
--select ciudad from proveedor where ciudad not in select ciudad form pieza;

-- >=ALL
-- >=ANY
-- <=ALL
-- <=ANY
-- <>ALL
-- <>ANY


-- select ... where /not/ exists (select ...)

select * from proveedor where not exists (select * from ventas where proveedor.codpro=ventas.codpro);
 Logs de Vistas Materializadas

 -- 3.19 3.20 3.21 3.22 3.23 
 
 --2.11 pag 26
 describe opc.Equipos;
 describe opc.Jugadores;
 describe opc.Encuentros;
 create table Equipos(
  codE char(3) constraint codE_es_pk primary key ,
  nombreE varchar2(30) not null unique,
  --UNIQUE ES QUE SEA CLAVE CANDIDATA
  localidad varchar2(30) not null,
  entrenador varchar2(30) not null,
  fecha_crea date not null);

create table Jugadores(
  codJ char(3) not null primary key,
  codE references Equipos(codE) not null,
  nombreJ char(30) not null);
create table Encuentros(
eq1 references Equipos(codE),
eq2 references Equipos(codE),
fecha date not null,
res1 number default 0 check (res1>=0) ,
res2 number default 0 check (res2>=0) , 
primary key(eq1,eq2));
  