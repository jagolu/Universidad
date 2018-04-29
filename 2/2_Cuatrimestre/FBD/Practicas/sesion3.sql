--PRUEBAS DE SELECT Y WHERE
select cantidad*12, codpro, codpie from ventas;
select cantidad*12 cant_anual, codpro, codpie from ventas;
select cantidad*12 cant_anual, codpro, codpie from ventas where cantidad/10>=150;
--PRUEBAS SUM() MAX MIN AVG STDDEV COUNT
select sum(cantidad) from ventas;
select sum(cantidad), avg(cantidad) from ventas;
select max(cantidad), min(cantidad) from ventas where fecha>='01\01\15' and fecha <='31\12\15';
select count(cantidad) from ventas;
--COUNT IGNORA LOS NULL
select count(distinct codpro) from ventas where codpie='P1';
--QUIEN HA HECHO EL PEDIDO MAS GRANDE
select codpro from ventas where cantidad=(select max(cantidad) from ventas);
--los proveedores que la casilla de su ciudad este vacia o que no lo este
select * from proveedor where ciudad is null;
select * from proveedor where ciudad is not null;
select * from ventas order by cantidad;--ordenador por cantidad
select fecha, cantidad, codpro from ventas order by fecha, cantidad desc;--si tienes fechas iguales, en esas fechas ordena por cantidad( canttidad en descendiente)


--SUBCONSULTAS
--ENCONTRAR LOS PROVEEDORES QUE HAN VENDIDO PIEZAS DE COLOR BLANCO
select distinct codpro from ventas, pieza where ventas.codpie=pieza.codpie and color='BLANCO';--forma 1
select distinct codpro from ventas where codpie in (select codpie from pieza where color='BLANCO');--forma 2
--PROVEEDORES QUE HAN VENIDO ALGUNA PIEZA QUE NO SEA BLANCA
select distinct codpro from ventas where codpie not in (select codpie from pieza where color='BLANCO');

--EJERCICIOS
--encontrar codigos de proyectos que usan piezas fabricadas en lisboa
select proyecto.codpj from pieza, proyecto, ventas where proyecto.codpj=ventas.codpj and ventas.codpie=pieza.codpie and pieza.ciudad='LISBOA';
--nombres de proyectos que usan piezas fabricadas en lisboa
select proyecto.nompj from pieza, proyecto, ventas where proyecto.codpj=ventas.codpj and ventas.codpie=pieza.codpie and pieza.ciudad='LISBOA';
--nombres de los proveedores que han hecho algun pedido que supere en cantidad a la media

--parejas de proyectos de la misma ciuada
select pro1.nompj,pro2.nompj,pro1.ciudad,pro2.ciudad from proyecto pro1, proyecto pro2 where pro1.ciudad=pro2.ciudad and pro1.codpj!=pro2.codpj and pro1.codpj<pro2.codpj;
--ventas en las que el proveedor y el proyecto sean de la misma ciudad (en parejas) mostrar proyecto proveedor y ciudad
select proyecto.nompj, proveedor.nompro, proyecto.ciudad, proveedor.ciudad from proveedor, proyecto, ventas where proveedor.ciudad=proyecto.ciudad and proveedor.codpro=ventas.codpro and proyecto.codpj=ventas.codpj;
--mostrar parejas de proveedores que han vendido la misma pieza
select distinct * from proveedor p1, proveedor p2, proyecto, ventas where p1.codpro!=p2.codpro;--NOESTA ACABADO