<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@ page import="java.io.*,java.util.*" %>
<%@ page import="com.example.myproject.MouseComparator" %>

<html>
	<head>
		<title>Comparador de precios</title>
		<link rel="stylesheet" type="text/css" href="styles.css"/>
		<title>Resultados de busqueda</title>
	</head>
	<body>
	<% 
	if(!request.getAttribute("MouseComparator").equals(null)){
		MouseComparator mc=(MouseComparator)request.getAttribute("MouseComparator");
		int cont=0;
		if(!mc.getUrlImagenAmazon().equals("")){%>
			<a href="<%out.print(mc.getUrlAmazon()); %>">
					<h2 id="amazon">Amazon</h2>
			</a>
			<article>
				<a href="<%out.print(mc.getUrlAmazon()); %>">
					<img id="imgAmazon" src="<%out.print(mc.getUrlImagenAmazon()); %>"/>
				</a>
					<p><%out.print(mc.getPrecioAmazon()); %>&#8364</p>
			</article>
		<%}
		else{
			cont++;
		}
		if(!mc.getUrlImagenBeep().equals("")){%>
			<a href="<%out.print(mc.getUrlBeep()); %>">
				<h2 id="beep">Beep</h2>
			</a>
			<article>
				<a href="<%out.print(mc.getUrlBeep()); %>">
					<img id="imgBeep" src="<%out.print(mc.getUrlImagenBeep()); %>"/>
				</a>
					<p><%out.print(mc.getPrecioBeep()); %>&#8364</p>
			</article>
		<%}
		else{
			cont++;
		}
		if(!mc.getUrlImagenPCC().equals("")){%>
			<a href="<%out.print(mc.getUrlPCC()); %>">
					<h2 id="pcc">PC Componentes</h2>
			</a>
			<article>
				<a href="<%out.print(mc.getUrlPCC()); %>">
					<img id="imgPCC" src="<%out.print(mc.getUrlImagenPCC()); %>"/>
				</a>
					<p><%out.print(mc.getPrecioPCC()); %>&#8364</p>
			</article>
		<%}
		else{
			cont++;
		}
		if(cont==3){
			%><p id="fail">No hemos encontrado ninguna oferta :(</p><%
		}
	}%>
	</body>
</html>