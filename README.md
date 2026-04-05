
    <figcaption align="center"><b>my momen ketika rill gw ketika dikasi tugas bawang</b></figcaption>
    <p align="center" style="width=60% height =60%;">
  <img src="https://media1.tenor.com/m/p-_J1OAA_RwAAAAC/sad.gif" width="100%" alt="momen ketika dikasi tugas bawang">
</p>

# Tugas Sekuro Day 2 - Destroyer Robot sang Penghitaman Massal

## Info Diri
- **NAMA** : aina
- **NIM**  : 13324106

## Informasi File-File Algoritma
Destroyer robot adalah sekumpulan file dalam satu (package) berbahasa ROS2 yang disimulasikan menjadi program dari sebuah robot tempur dengan 4 node:
- `auto_mode_destroyer` = bergerak otomastis tanpa inut
- `check_move_destroyer`= dikontrol keyboard sebagai input
- `drive_mode_destroyer`= penghubung antara input file publisher  drive/auto ke file subscriber algoritma move
- `move_destroyer` = menerima perintah untuk menggerakan robot tempur

## Diagram Node - Topic

auto_mode_destroyer  →  /autonomous_destroyer  →┐
→ check_move_destroyer → /power_destroyer → move_destroyer
drive_mode_destroyer →  /drive_destroyer       →┘
→ /move_type          → move_destroyer
##dependecies
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
[]
