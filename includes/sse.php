<?php 
function ssde($pass) {
	$algorithm = MCRYPT_BLOWFISH;
	$key = '849354ñlsdflkjsadlkñasdk';
	$mode = MCRYPT_MODE_CBC;
	$encrypted_data = base64_decode($pass);
	$decoded = @mcrypt_decrypt($algorithm, $key, $encrypted_data, $mode);	
	return $decoded;
}
?>