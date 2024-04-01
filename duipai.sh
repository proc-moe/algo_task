while true; do
python3 x.py > tmp.in
./tmp<tmp.in>tmp.out
./tmp2<tmp.in>tmp2.out
if diff tmp.out tmp2.out; then
printf AC
else 
echo WA
exit 0
fi
done