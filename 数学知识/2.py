n_quest=-1
len_quest=-1

n_quest=int(input())

for i in range(n_quest):
    len_quest=int(input())
    in_=input().split(' ')
    #print(in_)
    out=input().split(' ')
    out=[in_.index(out[j]) for j in range(len_quest)]
    pre_out=-1
    flag_brake=False
    for j in range(len(out)):
        if out[j]<pre_out:
            for k in range(out[j]+1,pre_out):
                if in_[k]!='out':
                    print('No')
                    flag_brake=True
                    break
        if flag_brake:
            break
        pre_out=out[j]
        in_[out[j]]='out'
    if not flag_brake:
        print('Yes')
