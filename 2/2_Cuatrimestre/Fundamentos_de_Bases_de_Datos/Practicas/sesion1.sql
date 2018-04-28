create table proveedor(
  codpro char(3) constraint codpro_es_pk primary key,
  nompro varchar2(30) constraint rellenar_nombre not null,
  status number(2) check ((status>=1) and (status<=10)),
  ciudad varchar2(15)
);
describe proveedor;
create table pieza(
  codpie char(3) constraint codpie_espk primary key,
  nompie varchar2(10) constraint nompie_not_null not null,
  color varchar2(10),
  peso number(5,2) check ( (peso>0) and (peso<=100) ),
  ciudad varchar2(15)
);
create table proyecto(
   codpj char(3) primary key,
   nompj varchar2(20) not null,
   ciudad varchar2(15)
);
create table ventas(
  codpro references proveedor(codpro),
  codpie references pieza(codpie),
  codpj references proyecto(codpj),
  cantidad number(4),
  --esto es un comentario--
  primary key (codpro, codpie, codpj)
);
describe ventas;