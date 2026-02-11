mkdir -p $1/testcases
cp template $1/$2.cc
sed -i '' "s/xxxx/$1/g" $1/$2.cc
sed -i '' "s/yyyy/$2/g" $1/$2.cc
touch $1/testcases/${2}_in
touch $1/testcases/${2}_out