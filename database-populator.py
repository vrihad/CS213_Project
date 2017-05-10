from random import randint

f=open("Database.txt", "w+")

space=" "
newline="\n"

f.write("0"+newline)
count=0
for i in range(0,26):
	string1=chr(97+i)
	for j in range(0,26):
		string2=chr(97+j)
		price=str(randint(4,24)*500)
		gear=str(randint(0,9)%2)
		typ=str(randint(1,4))
		category=str(randint(1,3))
		total=str(randint(2,10))
		count+=1
		f.write(string1+space+string1+string2+space+price+space+gear+space+typ+space+category+space+total+space+total+newline)

print count