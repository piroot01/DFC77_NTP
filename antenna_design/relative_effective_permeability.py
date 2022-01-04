#This script will return a relative effective permeability dependig on the input antenna values.

#external libraries

from math import log, exp, fabs
from scipy.integrate import quad

#input values

L = 0 #lenght of the ferrite rod
D = 0 #diameter of a ferrite rod
u = 0 #relative initial permeability of a ferrite rod
l_coil = 0 #lenght of the coil on a ferrite rod

def rel_eff_per(L, D, l_coil, u):
    #the mean effective permeability of a ferrite rod

    u_cs = u / (1 + (u - 1) * (D / L)**2 * (log(L / D) * (0.5 + 0.7 * (1 - exp(-u * 10**(-3)))) - 1))

    def u(x):
        return u_cs * (1 + (0.106 * (2 * fabs(x) / L)) - (0.988 * (2 * fabs(x) / L)**2))
    
    #integrate the u(x) assuming that the coil is in the middle of the rod

    u_partial, error = quad(u, -(l_coil / 2), (l_coil / 2))
    
    u_eff = u_partial * (1 / l_coil)

    return u_eff

