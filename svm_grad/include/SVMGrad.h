#ifndef __SVMGrad_H__
#define __SVMGrad_H__

#include "armadillo"

using namespace arma;
using namespace std;

/* SVMGrad: This structure holds the parameters of an RBF-SVM
 * D:       Datapoint Dimension
 * nSV:     # of SVs
 * b:       Offset
 * sigma:   kernel width
 * yalphas: alpha_i*yi     (1 X nSV)
 * SVs:     Support Vector (D X nSV)
*/

struct SVMGradModels{
    unsigned int D;
    unsigned int nSV;
    double gamma;
    double b;
    vec yalphas;
    mat SVs;
	double mux;
};

/* SVMGrad: This class computes the following function from an SMVGradModel
 *       y      = sign(Gamma(x))
 *       Gamma  = \sum_{i=1}^{N_sv}\alpha_iy_ik(x,x_i) + b
 *       DGamma = \sum_{i=1}^{N_sv}-1/2\sigma^2\alpha_iy_ik(x,x_i)(x-x_i)
*/

class SVMGrad
{
private:
    SVMGradModels SVMGradModel;

public:       
    SVMGrad(char *f_SVMGradmodel)
    double calculateClass(vec xi);
    double calculateGamma(vec xi);
    double calculateGammaGrad(vec xi);
};


#endif //__SVMGrad_H__
