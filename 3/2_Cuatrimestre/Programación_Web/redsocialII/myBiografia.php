<!doctype html>
	<head>
		<title>FindWork</title>
		<link rel="stylesheet" type="text/css" href="styles.css"/>
		<META charset="UTF-8">
		<script src="javascript.js"></script>
		<meta name=”viewport” content=”width=device-width”>
	</head>
	<body>
		<header>
			<section id="headerLogo">
				<a href="portada.php?n=0">
					<img src="logo.png"/>
				</a>
			</section>
			<section>
				<a href="portada.php?n=0">
					<h1>FindWork</h1>
				</a>
			</section>
			<section id="headerPerfil">
				<div>
					<a href="myprofile.php?n=0">
						<?php 
							$conexion = mysqli_connect("localhost", "pw_77148079", "Xpw_77148079");
    						mysqli_select_db($conexion, "pw_77148079");
    						$tildes=$conexion->query("SET NAMES 'utf8'");
    						session_start();
							$usuario=$_SESSION['usuario'];
    						$result=mysqli_query($conexion, "select imagen, hayImagen from usuarios where nombreUsuario='".$usuario."'");
    						$extraido=mysqli_fetch_array($result);
							echo '<p id="miNombre">'.$usuario.'</p>';
							if($extraido['hayImagen']){
								echo '<img src="data:image/jpg;base64,';
								echo base64_encode($extraido['imagen']);
								echo '"></a>';
							}
							else{
								echo '<img src="./fotoPerfilPredeterminada.png"></a>';
							}
    						echo '<a href="form.php?logout=1">
    							<p id="logout">Log out</p>
    						</a>';?>
				</div>
			</section>
		</header>
		<section id="bFI">
			<h3>
				<a href="myBiografia.php">
					Biografia
				</a>
				-
				<a href="fotos.php?n=0&perfil=<?php 
					echo $_SESSION['usuario']; ?>">
					Fotos
				</a>
				-
				<a href="myInformacion.php">
					Información
				</a>
			</h3>
		</section>
		<section id="usuariosRedSocial">
			<nav>
			<input type="checkbox" id="menuAmigos"></input>
				<ul>
					<li id="tituloMenuAmigos"><label for="menuAmigos">Mis Amigos</label></li>
					<?php 
						$conexion = mysqli_connect("localhost", "pw_77148079", "Xpw_77148079");
						mysqli_select_db($conexion, "pw_77148079");
						$tildes=$conexion->query("SET NAMES 'utf8'");
						$usuario=$_SESSION['usuario'];
						$result=mysqli_query($conexion, "select nombreUsuario, imagen, hayImagen from usuarios");
						while ($extraido=mysqli_fetch_array($result)){
							$nombre_usuario=$extraido['nombreUsuario'];
							$foto=$extraido['imagen'];
							if($usuario!=$nombre_usuario){
									echo '<li>
									<a href="friendprofile.php?perfil='.$extraido['nombreUsuario'].'&n=0">
										<p>'.$extraido['nombreUsuario'].'</p>';
										if($extraido['hayImagen']){
											echo '<img src="data:image/jpg;base64,';
											echo base64_encode($extraido['imagen']);
											echo '"></a>';
										}
										else{
											echo '<img src="./fotoPerfilPredeterminada.png"></a>';
										}
										echo '
								</li>';
							}
							
						}	
					?>
				</ul>
			</nav>
		</section>
		<aside>
			<nav>
			<input type="checkbox" id="menuUsuariosActivos"></input>
				<ul>
					<li id="usuarioActivos"><label for="menuUsuariosActivos">Usuarios Activos</label>
						<p>Usuarios Activos</p>
					</li>
					<?php 
						$conexion = mysqli_connect("localhost", "pw_77148079", "Xpw_77148079");
						mysqli_select_db($conexion, "pw_77148079");
						$tildes=$conexion->query("SET NAMES 'utf8'");
						$usuario=$_SESSION['usuario'];
						$result=mysqli_query($conexion, "select nombreUsuario, imagen, hayImagen, conectado from usuarios");
						while ($extraido=mysqli_fetch_array($result)){
							if($usuario!=$extraido['nombreUsuario'] && $extraido['conectado']==1){
								echo '<li>
								<a href="friendprofile.php?perfil='.$extraido['nombreUsuario'].'&n=0">
								<p>'.$extraido['nombreUsuario'].'</p>';
								if($extraido['hayImagen']){
									echo '<img src="data:image/jpg;base64,';
									echo base64_encode($extraido['imagen']);
									echo '"></a>';
								}
								else{
									echo '<img src="./fotoPerfilPredeterminada.png"></a>';
								}
								echo '</li>';
							}
						}	
					?>
				</ul>
			</nav>
		</aside>
		<section id="informacionPerfil">
			<form action="form.php" method="post" id="formMyBiografia" onsubmit="return comprobarBiografia()">
				<?php 
					$conexion = mysqli_connect("localhost", "pw_77148079", "Xpw_77148079");
					mysqli_select_db($conexion, "pw_77148079");
					$tildes=$conexion->query("SET NAMES 'utf8'");
					$usuario=$_SESSION['usuario'];
					$result=mysqli_query($conexion, "select biografia, imagen, hayImagen from usuarios where nombreUsuario='".$usuario."'");
					$extraido=mysqli_fetch_array($result);
					echo '<input id="cambiarBiografia" type="text" id="biografia" name="cambiarBiografia" placeholder="'.$extraido['biografia'].'"/>
					<br/>
					<input type="submit" id="actualizarBiografia" value="Actualizar"/>
					</form>';
					if($extraido['hayImagen']){
						echo '<img src="data:image/jpg;base64,';
						echo base64_encode($extraido['imagen']);
						echo '">';
					}
					else{
						echo '<img src="./fotoPerfilPredeterminada.png">';
					}
					?>
		</section>
		<footer>
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