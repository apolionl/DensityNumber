#include <iostream>
#include <cmath>
#include <iomanip>

constexpr long double avogadro {6.02214076E+023};
constexpr long double cc3_to_ang3  {1E+024};
void header();

class number_density
{
public:
    long double density, mol_mass, num_density, side_box_lenght, volume;
    number_density() {}
    number_density settings () {
        std::cout << "1. Phase experimental density \t[g/cm3]\n" ;
        std::cin >> density;
        std::cout << "1. Phase molecular mass  \t\t[g/mol]\n" ;
        std::cin >> mol_mass;
        std::cout << "   \n" ;
        return 0;
    }
    number_density indiv_number_density () {
        num_density = (density*avogadro)/(mol_mass*cc3_to_ang3);
        std::cout << num_density <<"\t[molecules/Ang3]\n";
        return 0;
    }
    number_density arista_box (long double num_mol){
    volume =num_mol/num_density
    side_box_lenght= std::cbrt(volume);
    }

};


int main()
{
    header();
    std::cout << std::setprecision(9);
    number_density solvent, solute;
    solvent.settings();
    solute.settings();
    solvent.indiv_number_density();
    solute.indiv_number_density();
    std::cout << "Number density for  solvent and solute  \n ";
    std::cout << "\nThe number density ratio (solvent/solute) is:  \t"  ;
    long double number_density_ratio = solvent.num_density/solute.num_density ;
    std::cout << number_density_ratio << "\t\n" ;

    std::cout << "**************************************************************************************\n" ;
    std::cout << "**************************************************************************************\n" ;
    std::cout << "\t\t\t\tNumber density of a mixture\n\n" ;
    std::cout << "As input it takes the number of molecules  (solvent + solute), \n" ;
    std::cout << "giving back the number density of the mixture and it`s density.\n\n" ;
    std::cout << "Number of solvent molecules:  \t\t\t" ;
    long double number_molecules_solvent ;
    std::cin >> number_molecules_solvent;
    std::cout << "\n";
    std::cout << "Number of solute molecules:  \t\t\t" ;
    long double number_molecules_solute ;
    std::cin >> number_molecules_solute;
    std::cout << "\n";
    std::cout<< "Total number of molecules in the mixture is :\t" <<  number_molecules_solute+number_molecules_solvent << '\n';
    solvent.arista_box(number_molecules_solvent);


    // This is the number of molecules of the mixture if all molecules were solvent
    // So one can obtain the new volumes, volumen mix
    long double mix_number_molecules; //
    mix_number_molecules = (number_molecules_solvent+(number_density_ratio*number_molecules_solute));
    number_density mixture;


    std::cout<< "\nMixture occupy :\t\t\t";
    mixture.volume = (mix_number_molecules/solvent.num_density);
    std::cout<< mixture.volume << "\t[Ang3]\n";
    std::cout<< "Mixture cubic box length :\t\t";
    mixture.side_box_lenght= std::cbrt(mixture.volume);
    std::cout<< mixture.side_box_lenght << "\t[Ang]\n";
    mixture.num_density=  (number_molecules_solute+number_molecules_solvent )/(mixture.volume);
    std::cout << "\nYour mixture number density is : \t" << mixture.num_density << "\t[molecules/Ang3]\n" ;
    long double relative_mix_mol_mass ;
    relative_mix_mol_mass = ((number_molecules_solvent*solvent.mol_mass)+(number_molecules_solute*solute.mol_mass))/(number_molecules_solute+number_molecules_solvent);
    mixture.density = ((number_density_mix*cc3_to_ang3*relative_mix_mol_mass)/(avogadro));
    std::cout << "Your mixture  density is : \t\t" << density_mix << "\t[g/cc3]\n" ;
    std::cout << "\t\t\t\t\tSayonara baby! \t\t\t\t\n" ;
    std::cout << "**************************************************************************************\n" ;
    std::cout << "**************************************************************************************\n" ;
    std::cout << "**************************************************************************************\n" ;


    return 0;

}

void header() {
    std::cout << "**************************************************************************************\n" ;
    std::cout << "**************************************************************************************\n" ;
    std::cout << "*\t\t\t\tNumber density calculator\t\t\t     *\n" ;
    std::cout << "**************************************************************************************\n" ;
    std::cout << "**************************************************************************************\n" ;
    std::cout << "Author : Vasquez Luis\t\t\t\t\t\t\t copyright \n" ;
    std::cout << "\n\n\n\n" ;
    std::cout << "This code calculates the density number of a solvent, solute and give back the \n";
    std::cout << "density of their mixture.\n\n\n" ;
    std::cout << "\t\t INPUT \n" ;
    std::cout << "1. Solvent experimental density \t[g/cm3] \n2. Solvent molecular mass  \t\t[g/mol]\n" ;
    std::cout << "3. Solute experimental density \t\t[g/cm3] \n4. Solute molecular mass  \t\t[g/mol]\n" ;
    std::cout << "**************************************************************************************\n" ;
}
