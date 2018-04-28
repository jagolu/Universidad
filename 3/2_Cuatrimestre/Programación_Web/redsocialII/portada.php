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
							$conexion = mysqli_connect("localhost", "*********", "*********");
    						mysqli_select_db($conexion, "*********");
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
						$conexion = mysqli_connect("localhost", "*********", "*********");
						mysqli_select_db($conexion, "*********");
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
						$conexion = mysqli_connect("localhost", "*********", "*********");
						mysqli_select_db($conexion, "*********");
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
		<section id="historias">
		<?php 
				$conexion = mysqli_connect("localhost", "*********", "*********");
				mysqli_select_db($conexion, "*********");
				$tildes=$conexion->query("SET NAMES 'utf8'");
				$usuario=$_SESSION['usuario'];
				$result=mysqli_query($conexion, "select entradas.*, usuarios.imagen, usuarios.hayImagen, usuarios.nombreUsuario from entradas, usuarios where usuarios.nombreUsuario=entradas.usuario order by entradas.id desc;");
				$n=$_GET["n"];
				$hasta=($n+1)*8;
				$historiasHechas=0;
				$variable=array("a", "b", "c");
				for($i=0;$i<($n*8);$i++){
					$extraido=mysqli_fetch_array($result);
				}
				for($i=($n*8); $i<$hasta && $extraido=mysqli_fetch_array($result);$i++){
					$historiasHechas++;
					echo '<article>';
						if($usuario==$extraido['nombreUsuario']) echo '<a href="myprofile.php?n=0">';
						else echo '<a href="friendprofile.php?perfil='.$extraido['nombreUsuario'].'&n=0">';
						echo '<h2 id="nombre">'.$extraido['nombreUsuario'].'</h2>
						</a>
						<div class="a">';
						if($usuario==$extraido['nombreUsuario']) echo '<a href="myprofile.php?n=0">';
						else echo '<a href="friendprofile.php?perfil='.$extraido['nombreUsuario'].'&n=0">';
							$olala="'".$extraido['nombreUsuario']."'";
						if($extraido['hayImagen']){
							echo '<img src="data:image/jpg;base64,';
							echo base64_encode($extraido['imagen']);
							echo '" onmouseover="cargarHistorias('.$olala.')"></a>';
						}
						else{
							echo '<img src="./fotoPerfilPredeterminada.png" onmouseover="cargarHistorias('.$olala.')"></a>';
						}
						echo	'<p id="fecHora">'.$extraido['fecha'].' '.$extraido['hora'].'</p>
						</div>
						<a href="entrada.php?id='.$extraido['id'].'">
							<h4>'.$extraido['titulo'].'</h4>
						</a>
						<p class?"contenidoHistoria">'.$extraido['texto'].'</p>
					</article>';
				}

				echo '
		</section>
		<section id="flechas">';
			if($n==0){
				echo '<img src="flechaTransparente.png">';
			}
			else{
				echo '<a href="portada.php?n=';
				echo ($n-1);
				echo '">
				<img src="flechaIzquierda.png">
				</a>';
			}
			if($extraido=mysqli_fetch_array($result)){
				echo '<a href="portada.php?n='; 
				echo $n+1; 
				echo '">
				<img src="flechaDerecha.png">
				</a>';
			}
			else{
				echo '<img src="flechaTransparente.png">';
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