clc;
clear;

% Amps
Is = 2.5;

% Ohms
Rs = 0.02;

% Gm
Gm = 0.0002;

% Ohms
Rl = 249000;

Vo = Is * Rs * Gm * Rl

Vdrop = Rs * Is

TF = Rs * Gm * Rl

Prs = Is * Is * Rs