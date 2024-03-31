echo "Glade results:"
echo
echo "Grammar & Recall & Precision & F1 & Time & #Queries"
for f in ./result/glade-results/*.asv; 
do g=$(basename $f); echo ${g%%-*} "&" $(cat $f); done
echo

echo "Arvada results:"
echo
python ./other-artifact/display_arvada_evaluation.py