#The main program that creates a graph of the dependence of the number of antenna revolutions on the antenna quality.

#external libraries

from relative_effective_permeability import rel_eff_per #better calculation than V!
from math import pi, log, sqrt
import matplotlib.pyplot as plt
from tabulate import tabulate

#necessary variables

L = 0 #inductance of the antenna
N = 0 #number of turns
Q = 0 #quality factor of an antenna
R_rez = 0 #resonant resistance of an antenna
C = 0 #capacitance of the resonant capacitator
C_1 = 0 #value of the band of the capacitator
C_2 = 0

#list for the plotting

list_L = []
list_Q = []
list_R_rez = []
list_N = []
list_C = []
list_f_bw = []
list_C_1 = []
list_C_2 = []

#physical constants

u_0 = 4 * pi * 10**(-7) #absolute permeability
c = 299792458 #speed of light
u_cu = 	1.256629 * 10**(-6) #permeability of copper
c_cu = 5.96 * 10**7 #conductivity of copper

#input values

w = 0.0002 #single wire diameter
k = 1 #number of wires in string
N_1 = 10 #inital number of turns
N_2 = 1000 #terminal number of turns
L_r = 0.0597 #lenght of the ferrite rod, 0,1248
D_r = 0.0096 #diameter of a ferrite rod, 0,0094
D_p = 0.0096 #diameter of the coil, 0.0108
L_coil = 0.0149 #lenght of the coil on a ferrite rod
s = 0 #coil shift from center of the ferrite rod
f = 77500 #resonant frequency
u = 250 #relative initial permeability of a ferrite rod
u_i = 2.5 #imaginary part of the relative initial permeability
R_rez_1 = 50000 #initial resonant resistance
R_rez_2 = 200000 #terminal resonant resistance
Q_min = 30 #minimal quality factor for the ic
f_bw = 0 #bandwidth of the antenna

#define functions

R_r = 0.0
R_f = 0.0
R_L = 0.0
L_air = 0.0

#table variables

table = []

#pre-calculations

W = w * sqrt(k) #string diameter
l = c / f #lambda
o = pi * (D_p + W) #circumference of a coil
S = pi * (D_r / 2)**2 #area of the ferrite rod
d = 1 / (sqrt(f * pi * u_cu * c_cu)) #skin effect

#calculate relative effective permeability based on the input values

u_eff = rel_eff_per(L_r, D_r, D_p, L_coil, u)

#Nagaoka’s factor

s_h = s / (L_r / 2)
K = -440.9943706 * s_h**8 + 1318.707293 * s_h**7 - 1604.5491034 * s_h**6 + 1021.078226 * s_h**5 - 363.8218957 * s_h**4 + 71.6178135 * s_h**3 - 7.6027344 * s_h**2 + 0.3013663 * s_h + 0.995

#radiation resistance

def rad_res(N):

    R_r = 20 * pi**2 * (o / l)**4 * u_eff**2 * N**2

    return R_r

#loss resistance

def loss_res(N):

    R_f = 2 * pi * f * u_eff * (u_i / u) * u_0 * N**2 * (S / L_r)

    return R_f

#ohmic resistance

def ohm_res(N):

    R_L = (N * pi * (D_p + w) / (c_cu * pi * w * d)) / k

    return R_L

#air core coil inductance

def air_core_coil(N):

    D_k = D_p + W
    k = L_coil / D_k
    L_air = ((u_0 * D_k * N**2) / 2) * (log(1 + (pi / (2 * k))) + (1 / (2.3004 + 3.437 * k + 1.7636 * k**2 - (0.47 / (0.755 + (1 / k))**(1.44)))))
#    L_air = L_air * 1000000

    return L_air

for n in range(N_1, N_2):
    L = u_eff * K * air_core_coil(n) #calculate the inductance
    C = 1 / (4 * pi**2 * f**2 * L) #calculate the capacitance
    Q = (2 * pi * f * L) / (rad_res(n) + loss_res(n) + ohm_res(n)) #calculate quality factor of the antenna
    R_rez = Q / (2 * pi * f * C) #calculate resonanace resistivity
    f_bw = f / Q
    C_1 = 1 / (4 * pi**2 * L * (f**2 - 2 * f * f_bw + f_bw**2)) - C
    C_2 = C - 1 / (4 * pi**2 * L * (f**2 + 2 * f * f_bw + f_bw**2))

    #check if is in parameters and write to the lists

    if (Q > Q_min):
        if (R_rez > R_rez_1 and R_rez < R_rez_2):
            list_L.append(L * 10**3)
            list_Q.append(Q)
            list_R_rez.append(R_rez / 10**3)
            list_N.append(n)
            list_C.append(C * 10**9)
            list_f_bw.append(f_bw)
            list_C_1.append(C_1 * 10**12)
            list_C_2.append(C_2 * 10**12)
#outputs

#plots

#1. Q to N

plt.plot(list_N, list_Q)
plt.grid(True)
plt.ylabel('Quality factor')
plt.xlabel('Number of threads')
plt.title('Dependence of quality on the number of threads')
#plt.text(63, 346.5, 'Effective permeability: ' + str(u_eff), style = 'italic', bbox = {'facecolor': 'skyblue', 'alpha': 0.75, 'pad': 10})

plt.savefig('Quality_to_number_of_turns.pdf') #save plot
plt.close()

#2. L to N

plt.plot(list_N, list_L)
plt.grid(True)
plt.ylabel('Inductance (uH)')
plt.xlabel('Number of threads')
plt.title('Dependence of inductance on the number of threads')
#plt.text(63, 346.5, 'Effective permeability: ' + str(u_eff), style = 'italic', bbox = {'facecolor': 'skyblue', 'alpha': 0.75, 'pad': 10})

plt.savefig('Inductance_to_number_of_threads.pdf') #save plot
plt.close()

#3. R_rez to N

plt.plot(list_N, list_R_rez)
plt.grid(True)
plt.ylabel('Resonance resistivity (kOhm)')
plt.xlabel('Number of threads')
plt.title('Dependence of resonance resistance on the number of threads')
#plt.text(63, 346.5, 'Effective permeability: ' + str(u_eff), style = 'italic', bbox = {'facecolor': 'skyblue', 'alpha': 0.75, 'pad': 10})

plt.savefig('Res_resistance_to_number_of_threads.pdf') #save plot
plt.close()

#tables

for i in range(0, len(list_L)):
   table.append([list_N[i], list_Q[i], list_L[i], list_C[i], list_R_rez[i], list_f_bw[i], list_C_1[i], list_C_2[i]])

table.insert(0, ['Number of threads', 'Quality factor', 'Induction (mH)', 'Capacitance (nF)', 'Resonant resistance (kOhm)', 'Bandwidth', 'C_1 (pF)', 'C_2 (pF)'])

f = open('table.txt', 'w')
f.write(tabulate(table, headers='firstrow', tablefmt='grid'))
f.close()
