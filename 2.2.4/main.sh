  #!/bin/bash

# 1. Create user 'atlas' with a password 'titan'
useradd -m -s /bin/bash atlas
echo 'atlas:titan' | chpasswd

# 2. Set up the SSH environment for the user (Atlas)
mkdir -p /home/atlas/.ssh
echo "SSH environment setup complete."

# 3. Create the 'firstflag.txt' file in the home directory of 'atlas'
echo "HD{mening_birinchi_bayrog'im!}" > /home/atlas/firstflag.txt
chown atlas:atlas /home/atlas/firstflag.txt
echo "First flag created."

# 4. Create a hidden file in the home directory of 'atlas'
echo "HD{bu_atlasning_bayrog'i}" > /home/atlas/.hiddenflag
chown atlas:atlas /home/atlas/.hiddenflag
echo "Hidden flag created."

# 5. Create the 'accept' program in the /home/atlas directory
cat << 'EOF' > /home/atlas/accept
#!/bin/bash
if [[ "$1" -ge 0 && "$1" -le 100 && "$2" =~ ^[a-zA-Z0-9]{5}$ ]]; then
  echo "HD{Bu_bayroqni_qo'lga_kiritdingmi?}"
else
  echo "Invalid input. Please provide a number between 0-100 and a 5-character alphanumeric string."
fi
EOF
chmod +x /home/atlas/accept
chown atlas:atlas /home/atlas/accept
echo "Program 'accept' created."

# 6. Create a directory with many files for the fourth challenge
mkdir -p /home/atlas/capture
for i in {1..50}; do
  if [ $i -eq 24 ]; then
    continue
  fi
  echo "Not the flag" > /home/atlas/capture/flag$i.txt
done
echo "OS{You're_getting_the_hang_of_this_3f8a91de}" > /home/atlas/capture/flag_real.txt
sleep 3
echo "HD{bu_qiyin_emasmi_3f8a91de}" > /home/atlas/capture/flag24.txt
chown -R atlas:atlas /home/atlas/capture
echo "Capture directory with flags created."

# 7. Create a maze of directories for the fifth challenge
mkdir -p /home/atlas/maze/dir{1..5}/subdir{1..5}
echo "HD{bu_rekursiya_qiziqmi?}" > /home/atlas/maze/dir3/subdir2/flag.txt
chown -R atlas:atlas /home/atlas/maze
echo "Maze directory created."

# 8. Create a directory with spaces in file names for the sixth challenge
mkdir -p "/home/atlas/spaces"
echo "HD{bayroqda bo'shliqlar mavjud}" > "/home/atlas/spaces/flag with spaces.txt"
chown -R atlas:atlas "/home/atlas/spaces"
echo "Spaces directory created."

# 9. Create maze2 and instructions for the seventh challenge
mkdir -p /home/atlas/maze2/{1..20}/{1..20}/{1..20}
echo "Bu yerga bor: 13/4/5" > /home/atlas/maze2/instructions001.txt
echo "bitta directory ortga qayt" > /home/atlas/maze2/13/4/5/instructions002.txt
echo "Bu yerga bor: 10/10/10" > /home/atlas/maze2/13/4/instructions003.txt
echo "Bu yerga bor: 11/3" > /home/atlas/maze2/10/10/10/instructions004.txt
echo "HD{labirintlar_unchalik_ham_oson_emas}" > /home/atlas/maze2/11/3/cat_me.txt
chown -R atlas:atlas /home/atlas/maze2
echo "Maze2 directory and instructions created."

# 10. Create a log file for the eighth challenge
mkdir -p /home/atlas/log
echo "HD{head_buyruqlarimi_yoki_tail_buyruqlari?}" > /home/atlas/log/logfile.txt
for i in {1..200}; do
  echo "This is log line $i" >> /home/atlas/log/logfile.txt
done
chown -R atlas:atlas /home/atlas/log
echo "Log directory created."

# Final message
echo "CTF environment setup complete. All flags and challenges are ready."
