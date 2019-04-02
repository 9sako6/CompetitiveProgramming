read n
diff=$((2025-n))
for((i=1;i<10;i++)){
  for((j=1;j<10;j++)){
    if [ $diff = $((i*j)) ]; then
      echo "$i x $j"
    fi
  }
}