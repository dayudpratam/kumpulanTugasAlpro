<?php
// konfigurasi database
$host = "localhost";
$user = "root";
$password = "";
$database = "db_kontak";

// membuat koneksi ke database
$conn = mysqli_connect($host, $user, $password, $database);

// mengecek koneksi
if (!$conn) {
    die("Koneksi gagal: " . mysqli_connect_error());
}
?>
