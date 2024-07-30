#include <iostream>
#include <algorithm>
#include <string>

//00:40
using namespace std;
int N, t_def, t_max, t_min;
string H;
int n;
const int NN = 10000+10;

typedef struct P{
    int t;
    string sender;
    string rec;
    string type;
    int ip;
    int timeout;
}P;
P p[NN];

enum IP_STATE{
    unassign,
    waitingassign,
    occupy,
    out
};

typedef struct IP{
    IP_STATE state;
    string owner;
    int out_time;
}IP;

IP ips[NN];

// 优化
int find_ip_by_name(string name){
    for(int i=1;i<=N;i++){
        if(ips[i].owner==name){
            return i;
        }
    }
    return 0;
}

int found_min_unassign(){
    for(int i=1;i<=N;i++){
        if(ips[i].state==unassign){
            return i;
        }
    }
    return 0;
}

int found_min_out(int t){
    for(int i=1;i<=N;i++){
        if(ips[i].state==out){
            return i;
        }
    }
    return 0;
}

void ret_offer(P ret){
    cout<<H<<" "<<ret.rec<<" "<<"OFR"<<" "<<ret.ip<<" "<<ret.timeout<<endl;
}

//todo 改ip的状态
void process_dis(int index){

    P ret;
    //1.检查是否有占用者为发送主机的 IP 地址：
    int found_ip = find_ip_by_name(p[index].sender);
    if(found_ip>0){
        ret.ip=found_ip;
    }
    else{
        int found_ip = found_min_unassign();
        if(found_ip>0){
            ret.ip=found_ip;
        }
        else{
            int found_ip = found_min_out(p[index].t);
            if(found_ip>0){
                ret.ip=found_ip;
            }
            else{
                return;
            }
        }
    }
    //2.将该 IP 地址状态设置为待分配，占用者设置为发送主机；
    ips[ret.ip].state=waitingassign;
    ips[ret.ip].owner=p[index].sender;
    //3.若报文中过期时刻为 0 ，则设置过期时刻为 t+Tdef;
    //否则根据报文中的过期时刻和收到报文的时刻计算过期时间，判断是否超过上下限：
    //  若没有超过，则设置过期时刻为报文中的过期时刻；
    //  否则则根据超限情况设置为允许的最早或最晚的过期时刻；
    if(p[index].timeout==0){
        ret.timeout=p[index].t+t_def;
    }else{
        int tmp = p[index].timeout-p[index].t;
        if(tmp>t_max){
            ret.timeout = p[index].t+t_max;
        }else if(tmp<t_min){
            ret.timeout = p[index].t+t_min;
        }else{
            ret.timeout = p[index].timeout;
        }
    }
    ips[ret.ip].out_time = ret.timeout;
    ret.rec = p[index].sender;
    //4.向发送主机发送 Offer 报文，其中，IP 地址为选定的 IP 地址，过期时刻为所设定的过期时刻。
    ret_offer(ret);
}

void clear_by_name(string name){
    for(int i=0;i<N;i++){
        if(ips[i].owner==name){
            if(ips[i].state==waitingassign){
                ips[i].state=unassign;
                ips[i].owner="";
                ips[i].out_time=0;
            }
        }
    }
}

void send_ack(P ret){
    cout<<H<<" "<<ret.rec<<" "<<"ACK"<<" "<<ret.ip<<" "<<ret.timeout<<endl;
}


void send_nak(P ret){
    cout<<H<<" "<<ret.rec<<" "<<"NAK"<<" "<<ret.ip<<" "<<0<<endl;
}
void precoess_req(int index){

    P ret;
    ret.rec = p[index].sender;
    ret.ip = p[index].ip;
    // 1.检查接收主机是否为本机：
    if(p[index].rec!=H){
       // 若不是，则找到占用者为发送主机的所有 IP 地址，对于其中状态为待分配的，
       // 将其状态设置为未分配，并清空其占用者，清零其过期时刻，处理结束
        clear_by_name(p[index].sender);
    }else{
        //2.检查报文中的 IP 地址是否在地址池内，且其占用者为发送主机，若不是，则向发送主机发送 Nak 报文，处理结束；
        if(p[index].ip<=N && p[index].ip>=1 && ips[p[index].ip].owner == p[index].sender){
            ips[p[index].ip].owner=p[index].sender;
            ips[p[index].ip].state=occupy;
            //4.设置过期时刻
            if(p[index].timeout==0){
                ret.timeout=p[index].t+t_def;
            }else{
                int tmp = p[index].timeout-p[index].t;
                if(tmp>t_max){
                    ret.timeout = p[index].t+t_max;
                }else if(tmp<t_min){
                    ret.timeout = p[index].t+t_min;
                }else{
                    ret.timeout = p[index].timeout;
                }
            }
            ips[p[index].ip].out_time=ret.timeout;
            send_ack(ret);
            }
        else{
            send_nak(ret);
            return;
        }
    }
}

void update_state(int t){
    for(int i=1;i<=N;i++){
        if((ips[i].state==waitingassign||ips[i].state==occupy) && ips[i].out_time<=t){
            if(ips[i].state==waitingassign){
                ips[i].state=unassign;
                ips[i].owner="";
                ips[i].out_time=0;
            }else{
                ips[i].state=out;
                ips[i].out_time=0;
            }
        }
    }
}


int main(){
    //N是ip个数
    cin>>N>>t_def>>t_max>>t_min>>H;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].t>>p[i].sender>>p[i].rec>>p[i].type>>p[i].ip>>p[i].timeout;
        update_state(p[i].t);
        if(p[i].rec==H || p[i].rec=="*"){

        }
        else{
            if(p[i].type=="REQ"){

            }else{
                continue;
            }
        }

        if(p[i].type!="DIS" || p[i].type!="REQ"){
        }else{
            continue;
        }


        if(p[i].rec=="*" && p[i].type!="DIS" || p[i].rec==H && p[i].type=="DIS"){
            continue;
        }

        // cout<<"here"<<endl;

        if(p[i].type=="DIS"){
            process_dis(i);
        }
        else if(p[i].type=="REQ"){
            precoess_req(i);
        }
        else if(p[i].type=="OFR"){
            continue;
        }
        else if(p[i].type=="ACK"){
            continue;
        }
        else if(p[i].type=="Nak"){
            continue;
        }
    }
    return 0;
}
