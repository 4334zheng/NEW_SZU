clc;
clear;

Input_gvn=[0.005  ; 0.01];
Output_tgt=[0.001 ;0.099];

step=0.5;

%layer1_para=[0.15,0.2,0.35;0.25,0.30,0.35];
%layer2_para=[0.40,0.45,0.60;0.50,0.55,0.6];

layer1_para=rand(2,3);
layer2_para=rand(2,3);

node_func=@(x) 1./(1+exp(-x));

learning_loop=10000;
mmse=zeros(1,learning_loop);

for I=1:learning_loop

layer1_input=layer1_para*[Input_gvn;1];
layer1_output=node_func(layer1_input);
layer2_input=layer2_para*[layer1_output;1];
layer2_output=node_func(layer2_input);

mmse(I)=0.5*sum((layer2_output-Output_tgt).^2);

delta_layer2=(layer2_output-Output_tgt).*layer2_output.*(1-layer2_output);
dev_layer2=delta_layer2*layer1_output';
delta_layer1=layer2_para(:,1:2)'*delta_layer2.*layer1_output.*(1-layer1_output);
dev_layer1=delta_layer1*Input_gvn';
layer2_para(:,1:2)=layer2_para(:,1:2)-step*dev_layer2;
layer1_para(:,1:2)=layer1_para(:,1:2)-step*dev_layer1;
end

plot(1:10:learning_loop,mmse(1:10:end),'-ro');
xlabel('learning round');
ylabel('total error (MMSE)');
grid on