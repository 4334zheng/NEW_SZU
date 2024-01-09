#include<iostream>
#include<cstring>
using namespace std;

class Tv
{
	friend class Remote;
	public:
		Tv(bool s,int mc){
			state = s,volume = 0,maxchannel = mc,channel = 0,mode = 0,input = 0;
		}
		void onoff(){
			state == 1? state = 0: state = 1;
		}
		bool ison() const{
			return state;
		}
		void set_vol(int v){
			volume = v;
		}
		void set_input(int i){
			input = i;
		}
		void set_chan(int c){
			channel = c;
		}
		bool volup(){
			if(state){
				if(volume<20){
					volume++;
					return 1;
				}
				return 0;
			}
			return 0;
		}
		bool voldown(){
			if(state){
				if(volume>0){
					volume--;
					return 1;
				}
				return 0;
			}
			return 0;
		}
		void chanup(){
			if(state){
				if(channel<maxchannel) channel++;
			}
		}
		void chandown(){
			if(state){
				if(channel>0) channel--;
			}
		}
		void set_mode(){
			if(state){
				mode==1?mode=0:mode=1;
			} 
		}
		void set_input(){
			if(state){
				input==1?input=0:input=1;
			}
		}
		void settings() const{
			if(state==0) cout<<"off ";
			else cout<<"on ";
			cout<<volume<<' '<<channel<<' ';
			if(mode == 0) cout<<"Cable ";
			else cout<<"Antenna ";
			if(input == 0) cout<<"VCR"<<endl;
			else cout<<"TV"<<endl;
		}
	private:
		int state;
		int volume;
		int maxchannel;
		int channel;
		int mode;
		int input;
};

class Remote
{
	private:
		int mode;
	public:
		Remote(int m):mode(m){}
		bool volup(Tv & t){
			return t.volup();
		}
		bool voldown(Tv & t){
			return t.voldown();
		}
		void onoff(Tv&t){
			t.onoff();
		}
		void chanup(Tv&t){
			t.chanup();
		}
		void chandown(Tv&t){
			t.chandown();
		}
		void set_chan(Tv&t,int c){
			t.channel = c;
		}
		void set_mode(Tv&t){
			t.set_mode ();
		}
		void set_input(Tv&t){
			t.set_input ();
		}
};

int main()
{
	bool state;
	int v,c,cnt;
	char s[4],m[8],i[4];
	cin>>s>>v>>c>>m>>i;
	if(strcmp(s,"off")==0) state = 0;
	else state = 1;
	if(strcmp(i,"VCR")==0) cnt = 0;
	else cnt = 1;
	Remote r(cnt);
	Tv tv(state,32);
	tv.set_input(cnt);
	tv.set_vol(v);
	tv.set_chan(c);
	char op[16];
	while(1){
		cin>>op;
		if(strcmp(op,"onoff")==0) r.onoff(tv);
		else if(strcmp(op,"volup")==0) r.volup(tv);
		else if(strcmp(op,"voldown")==0) r.voldown(tv);
		else if(strcmp(op,"chanup")==0) r.chanup(tv);
		else if(strcmp(op,"chandown")==0) r.chandown(tv);
		else if(strcmp(op,"set_chan")==0) 
		{
			int n;
			cin>>n;
			r.set_chan(tv,n);
		}
		else if(strcmp(op,"set_mode")==0) r.set_mode(tv);
		else if(strcmp(op,"set_input")==0) {
			r.set_input(tv);
			break;
		}
	}
	tv.settings();
	return 0;
}
