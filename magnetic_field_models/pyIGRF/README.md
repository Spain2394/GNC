# pyIGRF
## What is pyIGRF?  
This is a package of IGRF-12 (International Geomagnetic Reference Field) about python version. 
We can calculate magnetic field intensity and transform coordinate between GeoGraphical and GeoMagnetic.
It don't need any Fortran compiler. But it needs NumPy package.  

## How to Install?
Download this package and run install.
> pip install pyIGRF

## How to Use it?
First import this package.  
> ```import pyIGRF```

You can calculate magnetic field intensity.   
>```pyIGRF.igrf_value(lat, lon, alt, date)```

or calculate the annual variation of magnetic filed intensity.  
>```pyIGRF.igrf_variation(lat, lon, alt, date)```

the response is 7 float number about magnetic filed which is:  
- D: declination (+ve east)
- I: inclination (+ve down)
- H: horizontal intensity
- X: north component
- Y: east component
- Z: vertical component (+ve down)
- F: total intensity  
*unit: degree or nT*

If you want to use IGRF-12 more flexibly, you can use module *calculate*. 
There is two function which is closer to Fortran. You can change it for different coordination.
>```from pyIGRF import calculate```  

Another module *loadCoeffs* can be used to get *g[m][n]* or *h[m][n]* same as that in formula.
>```from pyIGRF.loadCoeffs import getCoeffs``` 



## Model Introduction and igrf12-coeffs File Download
https://www.ngdc.noaa.gov/IAGA/vmod/igrf.html