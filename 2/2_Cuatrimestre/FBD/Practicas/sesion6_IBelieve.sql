--PROVEEDORES QUE HAN SUMINISTRADO TODAS LAS PIEZAS BLANCAS
select codpro from ventas v1 where not exists
((select codpie from pieza where color='BLANCO') minus (select codpie from ventas v2 where v2.codpro=v1.codpro));
select codpro from proveedor p1 where not exists
((select codpie from pieza where color='BLANCO') minus (select codpie from ventas v2 where v2.codpro=p1.codpro));
--PROYECTOS QUE HAN SIDO ABASTECIDOS POR TODOS LOS PROVEEDORES CON ESTATUS MAYOR QUE 3
select * from proyecto p1 where not exists
( (select codpro from proveedor where status>3) minus (select codpro from ventas where ventas.codpj=p1.codpj) );

--PROYECTOS QUE HAN SIDO ABASTECIDOS POR TODOS LOS PROVEEDORES CON LA MISMA PIEZA CON ESTATUS MAYOR MAYOR QUE 3
select * from ventas j where not exists
( (select codpro from proveedor p1 where status>3) minus (select codpro from ventas v where v.codpj=j.codpj and adsfasf) );--falta terminarla


3.53 3.54 3.55 3.56

--3.57
((select codpro from ventas) minus (select codpro from ventas where cantidad<10)) intersect
select codpro from proveedor s where not exists
((select codpie from pieza where color='ROJO') minus (select codpie from ventas v where v.codpro=s.codpro));
--EJERCICIO 3.53
select codpro from proveedor p1 where not exists
( (select codpie from pieza where color='ROJO') minus (select codpie from ventas v1 where v1.codpro=p1.codpro) );
--EJERCICIO 3.55
select codpro from proveedor where not exists
( (select codpie from ventas v1 where v1.codpro=proveedor.codpro) minus (select codpie from pieza where color!='ROJO') );--mal