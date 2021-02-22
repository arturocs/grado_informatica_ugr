import random

def CyL(val, n, unused, op):
    if(len(val)>0):
        c=n // val[-1]
        r=n % val[-1]
        
        print(n,"=",val[-1],"*",c,"+",r)

        if n <  val[-1]:
            print(val[-1]," sin usar")
            unused.append(val[-1])
        else:
            op.append([n,val[-1],c,r])    
        val.pop(-1)
 
        if c not in val and c!=0 and c!=1:
            CyL(val,c,unused, op)
        if r not in val and r!=0 and r!=1:
            CyL(val,r,unused, op)  
 

def aproximar(val, num, res):
    i=0
    out=0
    if num > res:
        while i < len(val):
            if num > res+out:
                out+=val[i]
            i+=1    
    elif num < res:
        while i < len(val):
            if num < res+out:
                out-=val[i]
            i+=1        

    return out


vals=sorted(random.sample([1,2,3,4,5,6,7,8,9,10,50,75,100], 6))
vals_backup=vals.copy()

operaciones=[]
unused=[]
num=random.randint(100,1000)
print("num: ",num)
print(vals)

if num==100:
    print("encontrado 100 usando 100")
else:
	CyL(vals, num, unused, operaciones)

unused=sorted(list(set(vals)|set(unused)))
print("unused ",unused)

print("valores iniciales",vals_backup)

r_op=list(reversed(operaciones))
res=0
i=0
sumandos=[]

while i<len(r_op):
    if r_op[i][2] != 1:
        j=min(vals_backup, key=lambda x:abs(x-r_op[i][2]))
        sumandos.append(r_op[i][1]* j)
    else:
        sumandos.append(r_op[i][1])
    i+=1    

for s in sumandos:
    res+=s

print("resultado de CyL",res)
print("sumandos ", sumandos)

extra=aproximar(unused, num, res)

print("extra ",extra)

if abs(num-res) < abs(num-(res+extra)):
    print("resultado definitivo 1", res)
else:
    print("resultado definitivo 2", res+extra)   

print("operaciones ", operaciones)    