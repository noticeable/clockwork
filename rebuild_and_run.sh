source ./user_settings/private_settings.sh
./make_code.sh
if [ $? -eq 0 ]; then
  echo "Cmd: " $1
  ./a.out $1
else
  echo "Build FAILED"
fi


