<!doctype html>
	<head>
		<title>FindWork</title>
		<link rel="stylesheet" type="text/css" href="styles.css"/>
		<script src="javascript.js"></script>
		<META charset="UTF-8">
	</head>
	<body>
		<header id="index">
			<section id="headerLogo">
				<img src="logo.png"/>
			</section>
			<section id="headerNombre">
				<h1>FindWork</h1>
			</section>
			<section id="headerForm">
				<form action="form.php" method="post" id="formularioLogIn" onsubmit="return comprobarLogIn()">
					<div><label for="usuario">Usuario</label>
					<input type="text" id="usuarioR" name="usuarioLogIn"></div>
					<div><label for="contrasena">Contraseña</label>
					<input type="password" id="contrasena" name="contrasenaLogIn"></div>
					<input type="submit" id="entrar" value="Entrar"/>
					<p id="fakeValues"<?php 
						if(!isset($_GET['login'])){
							echo 'style="display: none;"';
						}
					?>>Valores erroneos</p>
				</form>
			</section>
		</header>
		<div>
			<section id="sectionImagenRS">
				<img src="ImagenRS.png"/>
			</section>
			<section id="sectionFormRegistro">
				<form action="form.php" method="post" id="formularioRegistro" onsubmit="return comprobarRegistro()">
					<h1>Registrarse</h1>
					<input class="registrarse" type="text" id="usuario" name="usuarioRegistro" placeholder="Nombre de usuario">
					<br/>
					<input class="registrarse" type="text" id="nombre" name="nombreRegistro" placeholder="Nombre">
					<br/>
					<input class="registrarse" type="text" id="apellidos" name="apellidosRegistro" placeholder="Apellidos">
					<br/> 
					<input class="registrarse" type="password" id="contrasena1" name="contrasena1Registro" placeholder="Contraseña">
					<br/>
					<label class="registrarse" for="fecha">Fecha de nacimiento</label>
					<input class="registrarse" type="date" id="fecha" name="fechaRegistro">
					<br/>
					<div id="generos">
						<fielset>
						Hombre<input type="radio" id="genero" name="generoRegistro" value="Hombre" checked/>
						<input type="radio" id="genero" name="generoRegistro" value="Mujer"/>Mujer</div>
						</fielset>
					<br/>
					<input type="submit" id="submitRegistro" value="Registrarse"/>
					<p id="usuarioYaExiste"<?php 
						if(!isset($_GET['registrarse'])) {
							echo 'style="display: none;"';
						}
					?>>Nombre de usuario ya existente</p>
				</form>
			</section>
		</div>
		<footer id="footerIndex">
			<p>
			<a href="contacto.html">
			Contacto
			</a>
			 - 
			 <a href="como_se_hizo.pdf">
			 Acerca de
			 </a>
			</p>
		</footer>
	</body>
</html>