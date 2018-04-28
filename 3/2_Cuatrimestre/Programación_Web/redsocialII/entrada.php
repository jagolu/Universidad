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
				<?php 
					$conexion = mysqli_connect("localhost", "pw_77148079", "Xpw_77148079");
					mysqli_select_db($conexion, "pw_77148079");
					$tildes=$conexion->query("SET NAMES 'utf8'");
					$id=$_GET["id"];
					$result=mysqli_query($conexion, "select usuario from entradas where id='".$id."'");
					$extraido=mysqli_fetch_array($result);
					echo '
				<a href="friendbiografia.php?perfil='.$extraido['usuario'].'">
					Biografia
				</a>
				-
				<a href="fotos.php?n=0&perfil='.$extraido['usuario'].'">
					Fotos
				</a>
				-
				<a href="friendinformacion.php?perfil='.$extraido['usuario'].'">
					Información
				</a>
				';?>
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
		<section id="historia">
			<article>
			<?php 
				$conexion = mysqli_connect("localhost", "pw_77148079", "Xpw_77148079");
				mysqli_select_db($conexion, "pw_77148079");
				$tildes=$conexion->query("SET NAMES 'utf8'");
				$usuario=$_SESSION['usuario'];
				$id=$_GET["id"];
				$result=mysqli_query($conexion, "select entradas.*, usuarios.imagen, usuarios.hayImagen, usuarios.nombreUsuario from entradas, usuarios where entradas.id=".$id." and usuarios.nombreUsuario=entradas.usuario;");
				$extraido=mysqli_fetch_array($result);
				echo '
				<a href="friendprofile.php?perfil='.$extraido['nombreUsuario'].'">
					<h1>'.$extraido['nombreUsuario'].'</h1>
				</a>
				<div id="fotoTiempo">';
				if($extraido['hayImagen']){
					echo '<img src="data:image/jpg;base64,';
					echo base64_encode($extraido['imagen']);
					echo '"></a>';
				}
				else{
					echo '<img src="./fotoPerfilPredeterminada.png"></a>';
				}
				echo '
					<h2>'.$extraido['fecha'].' '.$extraido['hora'].'</h2>
				</div>
				<h3>'.$extraido['titulo'].'</h3>
				<div id="fotoDescripcion">
					<h4>'.$extraido['texto'].'</h4>';
					if($extraido['hayImagenEntrada']){
						echo '<img src="data:image/jpg;base64,';
						echo base64_encode($extraido['imagenEntrada']);
						echo '"></div>';
					}
					else{
						echo '<img src="./fotoTranparentePorDefecto.jpg"></div>';
					}
			?>
			</article>
			<article id="comentarios">
				<?php 
					$conexion = mysqli_connect("localhost", "pw_77148079", "Xpw_77148079");
					mysqli_select_db($conexion, "pw_77148079");
					$tildes=$conexion->query("SET NAMES 'utf8'");
					$usuario=$_SESSION['usuario'];
					$id=$_GET["id"];
					$result=mysqli_query($conexion, "select  comentarios.*, usuarios.imagen, usuarios.hayImagen from usuarios, comentarios where comentarios.id=".$id." and comentarios.usuario=usuarios.nombreUsuario order by id2 asc;");
					$id22=-1;
					while ($extraido=mysqli_fetch_array($result)){
						echo '
							<article>
								<a href="friendProfile.php?user='.$extraido['usuario'].'">
									<h4>'.$extraido['usuario'].'</h4>';
									if($extraido['hayImagen']){
										echo '<img src="data:image/jpg;base64,';
										echo base64_encode($extraido['imagen']);
										echo '">';
									}
									else{
										echo '<img src="./fotoPerfilPredeterminada.png">';
									}
							echo '
								</a>
								<h5>'.$extraido['fecha'].' '.$extraido['hora'].'</h5>
								<p>'.$extraido['texto'].'</p>
							</article>';
							$id22++;
					}
					echo '<article>';
						$result1=mysqli_query($conexion, "select imagen, hayImagen from usuarios where nombreUsuario='".$usuario."'");
						$extraido1=mysqli_fetch_array($result1);
						echo '<h4>'.$usuario.'</h4>
						<div id="miComentario">';
						if($extraido1['hayImagen']){
							echo '<img src="data:image/jpg;base64,';
							echo base64_encode($extraido1['imagen']);
							echo '">';
						}
						else{
							echo '<img src="./fotoPerfilPredeterminada.png"></a>';
						}
						$id2=$id22+1;
						echo '
						<form action="form.php?id='.$id.'&id2='.$id2.'" method="post" id="formComentario" onsubmit="return comprobarComentario()">
							<input type="text" id="escribirComentario" name="escribirComentario"/>
							<input type="submit" id="enviarComentario" value="Comentar"/>
						</form>';
					?>
					</div>
				</article>
			</article>
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