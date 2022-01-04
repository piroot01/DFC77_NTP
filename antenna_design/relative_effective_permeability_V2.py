#V2 of the programme

#This script will return a relative effective permeability dependig on the input antenna values.

#external libraries

from math import pi, log

#input values

L_r = 0 #lenght of the ferrite rod
D_r = 0 #diameter of the ferrite rod
D_p = 0 #diameter of the profile of the coil
L_coil = 0 #lenght of the coil
u = 0 #relative initial permeability of a ferrite rod

#physical constants

epsilon_0 = 8.854187 * 10**(-12) #absolute permittivity 

#necessary variables

l_1 = 0 #dimensional character of the coil
phi_delta = 0 #magnetic flux phi_delta = phi / phi_max
C_anf = 0 #antenna capacitance
k = 0
x = 0
u_fe = 0 #apparent permeability

def rel_eff_per(L_r, D_r, D_p, L_coil, u):
    
    l_1 = L_coil + 0.45 * D_p
    phi_delta = 1 / (1 + (((L_r - L_coil) / D_r)**(1.4) / (5 * u)))
    C_anf = 0.5 * pi * epsilon_0 * (L_r - L_coil) / (log(2 * (L_r + D_r) / D_r) - 1)
    k = ((phi_delta * C_anf / epsilon_0) + (2 * D_r)) / (2 * D_p)
    x = 5.1 * (l_1 / D_p) / (1 + 2.8 * (D_p / l_1))
    u_fe = (u - 1) * (D_r / D_p)**2 + 1

    u_eff = (1 + x) / ((1 / k) + (x / u_fe))

    return u_eff
