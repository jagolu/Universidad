--TOTAL DE VENTAS EN 2015 DE CADA PROVEEDOR EN 2015 ORDENADO POR PROVEEDOR
select codpro, sum(cantidad) from ventas where to_char(fecha,'yyyy')='2015' group by codpro order by codpro;
--TOTAL DE VENTAS EN 2015 DE CADA PROVEEDOR ORDENADO POR PROVEEDOR Y QUE HAYAN VENDIDO MAS DE 1000 UNIDADES
               --con group by no se puede poner mas where y hay que poner having(que es igual que where)
select codpro, sum(cantidad) from ventas where to_char(fecha,'yyyy')='2015' group by codpro having sum(cantidad)>1000 order by codpro;
--las cantidades vendidas por cada proveedor cada uno de los años
select codpro, to_char(fecha,'yyyy'), sum(cantidad) 
from ventas group by codpro, to_char(fecha,'yyyy') order by codpro, to_char(fecha,'yyyy');
--contar el numero de piezas diferentes que se le han vendido a cada proyecto
select v.codpj,j.nompj, count(distinct codpie) from ventas v, proyecto j where v.codpj=j.codpj group by v.codpj, nompj;

select nompj, j.codpj, npiezas
from (select cp.codpj, count(distinct cp.codpie) npiezas 
from ventas group by cp.codpj) cp, proyecto j 
where j.codpj=cp.codpj;--no va

--encuentra el proveedor que mas ha vendido
select codpro, sum(cantidad) suma from ventas
group by codpro 
having sum(cantidad)>=all( select sum(cantidad) from ventas group by codpro );
--el proveedor que mas ha vendido durante 2015
select codpro, sum(cantidad) suma from ventas where to_char(fecha,'yyyy')='2015'
group by codpro 
having sum(cantidad)>=all( select sum(cantidad) from ventas group by codpro );
select * from ventas;
--proveedor que mas ha vendido con su nombre y ciudadç
select nompro, ciudad, mejor.codpro from
(select codpro, sum(cantidad) suma from ventas
group by codpro 
having sum(cantidad)>=all( select sum(cantidad) from ventas group by codpro )) mejor, proveedor
where mejor.codpro=proveedor.codpro;

--3.35,3.36,3.42,3.43,3.45,3.49,3.50,3.52,3.53,3.55,3.56,3.58,c'est fini