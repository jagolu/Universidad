--VISTAS
create view ventas_anuales (anualidad, total) as
(select to_char(fecha,'yyyy'),sum(cantidad)
from ventas
group by to_char(fecha,'yyyy'));
describe user_views;
select * from user_views;
drop view ventas_animales;
select * from ventas_anuales;
select * from all_views;

--INDICES
create index nombre_indx on proveedor(nompro);
--CLUSTER (?)
--muy util para entidades debiles con fuertes
create cluster pror_vta ( codpro char(3));
create table proveedor2(
  codpro char(3) primary key,
  nompro varchar2(30)  not null,
  status number(2) check ((status>=1) and (status<=10)),
  ciudad varchar2(15)
) cluster pror_vta (codpro);
create table ventas2(
  codpro char(3) references proveedor(codpro),
  codpie references pieza(codpie),
  codpj references proyecto(codpj),
  cantidad number(4),
  primary key (codpro, codpie, codpj)
)cluster pror_vta (codpro) ;
create index ind_cluster on cluster pror_vta; --si no haces esto no puedes insertar ni nada
select * from proveedor p, ventas v where
p.codpro=v.codpro;
select * from proveedor2 p, ventas2 v where
p.codpro=v.codpro;

--antes de borrar los cluster es aconsaejable guardar las tablas en otro lado, porque las tablas que hay dentro se borran si o si
--borrar cluster FORMA 1
drop table proveedor2;
drop table ventas2;
drop cluster pror_vta;

--borrar cluster FORMA 2
drop cluster pror_vta including tables;
