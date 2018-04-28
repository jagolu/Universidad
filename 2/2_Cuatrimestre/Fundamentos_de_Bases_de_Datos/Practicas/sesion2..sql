insert into proveedor values('S1','JOSE FDEZ',2,'MADRID');
select * from proveedor;
insert into proveedor values( 'S2','MANUEL VIDAL',1,'LONDRES' );
insert into proveedor values( 'S3','LUISA GOMEZ',3,'LISBOA' );
insert into proveedor values( 'S4','PEDRO SANCHEZ',4,'PARIS' );
insert into proveedor values( 'S5','MARIA REYES',5,'ROMA' );

insert into pieza values( 'P1','TUERCA','GRIS',2.5,'MADRID' );
insert into pieza values( 'P2','TORNILLO','ROJO',1.25,'PARIS' );
insert into pieza values( 'P3','ARANDELA','BLANCO',3,'LONDRES' );
insert into pieza values( 'P4','CLAVO','GRIS',5.5,'LISBOA' );
insert into pieza values( 'P5','ALCAYATA','BLANC0',10,'ROMA' );

commit;


insert into proyecto values( 'J1','PROYECTO 1','LONDRES' );
insert into proyecto values( 'J2','PROYECTO 2','LONDRES' );
insert into proyecto values( 'J3','PROYECTO 3','PARIS' );
insert into proyecto values( 'J4','PROYECTO 4','ROMA' );

commit;


select * from opc.ventas;

alter table ventas add(fecha date);

describe opc.ventas;
insert into ventas(select * from opc.ventas);
select * from ventas;
describe ventas;

commit;

select * from ventas where fecha>'01/01/13';
select * from ventas where cantidad>400;

#--MOSTRAR LOS CODPIE DE LOS ARTICULOS VENDIDOS EN MAS DE 400 ARTICULOS

select codpie from ventas where cantidad>400;


--PRODUCTO CARTESIANO

select * from proveedor, ventas;

select * from proveedor,ventas where proveedor.codpro=ventas.codpro;

select nompro,codpie,cantidad,fecha,proveedor.codpro from proveedor,ventas where proveedor.codpro=ventas.codpro;



--ENCONTRAR LOS NOMBRES DE LOS PROVEEDORES QUE HAN VENDIDO LA PIEZA P2
--DISTINCT ELIMINA COSAS REPETIDAS EN LA SOLUCION

select distinct nompro from proveedor,ventas where ((proveedor.codpro=ventas.codpro) and (codpie='P2'));
