select nompie from pieza where (color='ROJO' or color='GRIS') and ciudad='MADRID';

select codpie from ventas where (cantidad>=200 and cantidad<=300);

select nompie from pieza where nompie like 'TORNILLO' or nompie like 'tornillo';

(select distinct ciudad from proveedor where status>2) minus (select distinct ciudad from pieza where codpie= 'P1'); 

(select codpj from ventas where codpro='P1') minus (select codpj from ventas where codpro<>'P1');

(select ciudad from pieza) union (select ciudad from proveedor) union (select ciudad from proyecto);

(select ciudad from pieza) union all (select ciudad from proveedor) union all (select ciudad from proyecto);

select distinct proyecto.codpj, pieza.codpie, proveedor.codpro from pieza, proveedor, proyecto 
where proyecto.ciudad='LONDRES' and pieza.ciudad='LONDRES' and proveedor.ciudad='LONDRES';

select distinct proyecto.codpj, pieza.codpie, proveedor.codpro from pieza, proveedor, proyecto, ventas 
where (proyecto.ciudad='LONDRES' and pieza.ciudad='LONDRES' and proveedor.ciudad='LONDRES') 
and (proyecto.codpj=ventas.codpj and  pieza.codpie=ventas.codpie and proveedor.codpro=ventas.codpro);

select distinct p1.codpro, p2.codpro from proveedor p1, proveedor p2 where p1.codpro<> p2.codpro and p1.codpro<p2.codpro;


select codpie from pieza minus select p1.codpie from pieza p1, pieza p2 where p1.peso<=p2.peso and p1.codpie!=p2.codpie;
--3.12
select distinct nompro, cantidad from proveedor natural join (select * from ventas where cantidad>800);
--3.15
select distinct codpie from pieza natural join ( select codpie from ventas natural join (select * from proveedor where ciudad='MADRID'));
--3.16
select distinct ventas.codpie, k1.ciudad from ventas, (select distinct codpro, ciudad from proveedor natural join (select * from proyecto)) k1
where ventas.codpro=k1.codpro;
--3.19
select codpie from pieza where codpie in (select codpie from ventas where codpro in (select codpro from proveedor where ciudad='MADRID'));
--3.20
select distinct codpj from proyecto, pieza where proyecto.ciudad=pieza.ciudad;
--3.21
(select codpro from ventas where codpie in (select codpie from pieza where color='ROJO')) minus (select codpro from proveedor where ciudad='LONDRES');
--3.23
select codpie from pieza p1 where p1.peso>= all (select peso from pieza);
--3.24            
select codpie from pieza where not exists (
(select distinct codpro, codpie from ventas, proyecto where ventas.codpj=proyecto.codpj and ciudad='LONDRES')
minus 
(select codpie from pieza)
);
--3.25


--3.26
select count(cantidad) from ventas where cantidad>1000;
--3.27
select max(peso) from pieza;
--3.28
select codpie from pieza where peso in(select max(peso) from pieza);
--3.30

--3.31
select distinct codpie, stddev(cantidad) from ventas group by (codpie);

--3.32
select codpro, codpie, avg(cantidad) from ventas
where codpie='P1'
group by (codpro, codpie) 
having count(*) between 2 and 10;
--3.35
select nompro from proveedor where codpro in
(select distinct codpro from ventas group by (codpro, cantidad)
having sum(cantidad) >1000);
--3.36
select codpie, max(v1.cantidad) from ventas v1
group by v1.codpie order by codpie;
--
describe dictionary;
select * from dictionary where table_name like '%index%';

--EJERCICIOS ADICIONALES
--3.42
select codpro from ventas 
where codpro<>'S1' group by(codpro)
having sum(cantidad) >(select sum(cantidad) from ventas 
where codpro='S1');
--3.43
select codpro from ventas
group by (codpro) having(sum(cantidad)) >=all
(select sum(cantidad) from ventas 
group by(codpro)); 
--3.44

--3.45 PERO CON AL MENOS 4 VENTAS
(select codpro from ventas 
group by (codpro) having count(*) >=4);
--3.46
select codpro from ventas where not exists
(select distinct codpie from ventas where codpro='S1')
minus (select distinct codpie, codpro from ventas
order by codpro);
--3.47

--3.48
select codpj from proyecto p1 where not exists
((select distinct codpro from ventas v1
where codpie='P3') minus
(select distinct codpro from ventas v2
where p1.codpj=v2.codpj));
--3.49
select codpro, avg(cantidad) from ventas
group by (codpro) having codpro in
(select distinct codpro from ventas
where codpie='P3');
--3.50
--3.51
--3.52
select codpro, avg(cantidad), to_char(fecha, 'YYYY') from ventas 
group by(codpro, to_char (fecha,'YYYY')) order by codpro, to_char(fecha, 'YYYY');
--3.53
select distinct codpro from ventas
where codpie in 
(select codpie from pieza where color='ROJO');
--3.54
select distinct codpro from ventas v1 where not exists(
(select codpie from pieza p1 where color='ROJO') minus
(select codpie from ventas v2 
where v2.codpro=v1.codpro and v2.codpie in
(select codpie from pieza where color='ROJO')));
--3.55
(select codpro from proveedor) minus
(select distinct codpro from ventas where codpie in
(select codpie from pieza where color<>'ROJO'));
--3.56
select nompro from proveedor where codpro in
(select  codpro from (select codpro, codpie from ventas where codpie in
(select codpie from pieza where color='ROJO')) tablica group by(codpro) having count(*)>1);
--3.57
(select codpro from ventas where codpro in (select distinct codpro from ventas v1 where not exists(
(select codpie from pieza p1 where color='ROJO') minus
(select codpie from ventas v2 
where v2.codpro=v1.codpro and v2.codpie in
(select codpie from pieza where color='ROJO'))) )) minus (select distinct codpro from ventas where cantidad<=20);
--3.58
--3.59
select * from ventas where to_char(fecha, 'MM/YYYY')='09/2010';


--EJERCICIOS BASKET

