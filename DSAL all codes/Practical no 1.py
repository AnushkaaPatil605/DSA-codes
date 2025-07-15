n=int(input("Enter the total no of telephone numbers you want to enter: "))
tel=[]
for i in range (n):
    m=int(input("Enter the telephone number: "))
    tel.append(m)
table_size=int(input("Enter the table size: "))


def linear_hash(tel):
    second_list= [None]*table_size
    for i in tel:
        index=i% table_size
        while second_list[index] is not None:       
            index=(index+1)%table_size
        second_list[index]=i
    
    print("Hash table: ",second_list)

def qudratic(tel):
    second_list= [None]*table_size
    for j in tel:
        index=j% table_size
        i=1
        while second_list[index] is not None:       
            index=(index+ i**2 )%table_size
            i=i+1
        second_list[index]=j
    
    print("Hash table: ",second_list)

def double_hashing(tel):
    second_list= [None]*table_size
    def hash1(key):
       return key% table_size
    
    def hash2(key):
        return 1+(key%((table_size)-1))
    for j in tel:
        index=hash1(j)
        offset=hash2(j)
        i=0
        while second_list[index] is not None:     
            index=(index+i % offset)% table_size
            i+=1
        second_list[index]=j
    print("Hash table: ",second_list)
 


while(1):
    print("********PRACTICAL NO.1(A-1)**********")
    print("1.LINEAR HASHING")
    print("2.QUADRATIC HASHING")
    print("3.DOUBLE HASHING")
    print("4.EXIT")
    ch=int(input("Enter choice:"))
    if ch==1:
        linear_hash(tel)
    
    if ch==2:
        qudratic(tel)

    if ch==3:
        double_hashing(tel)

    if ch==4:
        print("Terminated successfully")
        break