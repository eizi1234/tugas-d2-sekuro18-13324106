<div align ="center">
    <figcaption><center><b>my momen ketika rill gw ketika dikasi tugas bawang</b></center></figcaption>
  <img src="https://media1.tenor.com/m/p-_J1OAA_RwAAAAC/sad.gif" width="60%" height = 60% alt="momen ketika dikasi tugas bawang">
</div>

# Tugas Sekuro Day 2 - Destroyer Robot sang Penghitaman Massal

## Info Diri
- **NAMA** : aina
- **NIM**  : 13324106

## Informasi File-File Algoritma
Destroyer robot adalah sekumpulan file dalam satu (package) berbahasa ROS2 yang disimulasikan menjadi program dari sebuah robot tempur dengan 4 node:
- `auto_mode_destroyer` = bergerak otomastis tanpa inut
- `check_move_destroyer`= penghubung antara input file publisher  drive/auto ke file subscriber algoritma move
- `drive_mode_destroyer`= dikontrol keyboard sebagai input 
- `move_destroyer` = menerima perintah untuk menggerakan robot tempur

## Diagram Node - Topic

<img align = "center" width="808" height="192" alt="Screenshot 2026-04-05 093708" src="https://github.com/user-attachments/assets/e3fe7204-082c-414b-b707-4319ff9e923e" />

auto_mode_destroyer  →  /autonomous_destroyer  →┐
→ check_move_destroyer → /power_destroyer → move_destroyer
drive_mode_destroyer →  /drive_destroyer       →┘
→ /move_type          → move_destroyer


## dependecies
- ROS2 Humble
- rclcpp
- geometry_msgs
- std_msgs

## Cara Menjalankan
semuanya dibuat dan di terminal. Maka command-command hanya dipakai untuk terminal
### Jalankan semua node langsung (Switch ON):
```
source install/setup.bash
ros2 launch destroyer_robot destroyer_launch.py
```

## jalankan node satu per satu:
```
ros2 run destroyer_robot move_destroyer
ros2 run destroyer_robot check_move_destroyer
ros2 run destroyer_robot auto_mode_destroyer
ros2 run destroyer_robot drive_mode_destroyer
```
## video presentasi


<div align="center">
  <a href="https://youtu.be/9uTFwDSejLw?si=YH9nTf2eIbJ5Ewbk">
    <img width="638" height="365" alt="Screenshot 2026-04-05 095205" src="https://github.com/user-attachments/assets/b6aa5c55-eaab-4120-b7d1-1bc61c5b0393" />
  </a>
  <p><i>Klik gambar di atas untuk menonton video di YouTube</i></p>
</div>

<div align ="center">
<p> my momen gw ketika tugasnya udah done selesai</p>
<img align ="center" src="https://media1.tenor.com/m/UKimM5KATKAAAAAC/mas-rusdi-si-imut.gif" width = 50% height = 50%>
</div>

