<!DOCTYPE html>
<html>
<head>
    <title>CRUD dengan PHP dan MySQL</title>
</head>
<body>
    <?php
    // menghubungkan ke file koneksi
    require_once("konek.php");

    // inisialisasi variabel
    $nama = "";
    $email = "";
    $pesan = "";
    $tanggal = date("Y-m-d");

    // mengatur mode operasi (tambah atau edit)
    if (isset($_POST["tambah"])) {
        // jika mode tambah
        $nama = $_POST["nama"];
        $email = $_POST["email"];
        $pesan = $_POST["pesan"];

        // menyimpan data ke database
        $sql = "INSERT INTO kontak (nama, email, pesan, tanggal) VALUES ('$nama', '$email', '$pesan', '$tanggal')";
        mysqli_query($conn, $sql);
    } elseif (isset($_POST["ubah"])) {
        // jika mode edit
        $id = $_POST["id"];
        $nama = $_POST["nama"];
        $email = $_POST["email"];
        $pesan = $_POST["pesan"];

        // mengubah data di database
        $sql = "UPDATE kontak SET nama='$nama', email='$email', pesan='$pesan' WHERE id=$id";
        mysqli_query($conn, $sql);
    } elseif (isset($_GET["hapus"])) {
        // jika mode hapus
        $id = $_GET["hapus"];

        // menghapus data dari database
        $sql = "DELETE FROM kontak WHERE id=$id";
        mysqli_query($conn, $sql);
    }

    // menampilkan data dari database
    $sql = "SELECT * FROM kontak ORDER BY tanggal DESC";
    $result = mysqli_query($conn, $sql);
    ?>

    <h1>CRUD dengan PHP dan MySQL</h1>
    <hr>
    <form method="post" action="index.php">
        <?php if (isset($_GET["edit"])) { // Jika mode edit ?>
            <h2>Edit Data</h2>
            <?php
            $id = $_GET["edit"];
            $sql = "SELECT * FROM kontak WHERE id=$id";
            $result = mysqli_query($conn, $sql);
            $row = mysqli_fetch_assoc($result);
            ?>
            <input type="hidden" name="id" value="<?php echo $row["id"]; ?>">
            Nama: <input type="text" name="nama" value="<?php echo $row["nama"]; ?>"><br><br>
            Email: <input type="email" name="email" value="<?php echo $row["email"]; ?>"><br>
            Pesan: <textarea name="pesan"><?php echo $row["pesan"]; ?></textarea><br><br>
            <input type="submit" name="ubah" value="Ubah">
            <a href="index.php">Batal</a>
        <?php } else { // Jika mode tambah ?>
            <h2>Tambah Data</h2>
            Nama: <input type="text" name="nama" value="<?php echo $nama; ?>"><br><br>
            Email: <input type="email" name="email" value="<?php echo $email; ?>"><br><br>
            Pesan: <textarea name="pesan"><?php echo $pesan; ?></textarea><br><br>
            <input type="submit" name="tambah" value="Tambah">
        <?php } ?>
    </form>
    <hr>
    <h2>Data Kontak</h2>
    <table border="1">
        <tr>
            <th>No.</th>
            <th>Nama</th>
            <th>Email</th>
            <th>Pesan</th>
            <th>Tanggal</th>
            <th>Aksi</th>
        </tr>
        <?php
        $no = 1;
        while ($row = mysqli_fetch_assoc($result)) {
            echo "<tr>";
            echo "<td>" . $no++ . "</td>";
            echo "<td>" . $row["nama"] . "</td>";
            echo "<td>" . $row["email"] . "</td>";
            echo "<td>" . $row["pesan"] . "</td>";
            echo "<td>" . $row["tanggal"] . "</td>";
            echo "<td>";
            echo "<a href='index.php?edit=" . $row["id"] . "'>Edit</a> | ";
            echo "<a href='index.php?hapus=" . $row["id"] . "' onClick='return confirm(\"Apakah Anda yakin ingin menghapus data?\")'>Hapus</a>";
            echo "</td>";
            echo "</tr>";
        }
        ?>
    </table>

    <?php
    // menutup koneksi database
    mysqli_close($conn);
    ?>
</body>
</html>

