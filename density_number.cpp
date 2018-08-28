#include <iostream>
#include <cmath>
#include <iomanip>

constexpr long double avogadro {6.02214076E+023};
constexpr long double cc3_to_ang3  {1E+024};
void header();
long double get_exp_density();
long double get_mol_mass();
long double get_number_density(long double dens, long double mol_mass);
long double get_volume(long double num_molecules, long double density_number);

int main()
{
    header();
    std::cout << std::setprecision(9);
    std::cout << "1. Solvent experimental density \t[g/cm3]\n" ;
    long double density_solvent = get_exp_density();
    std::cout << "2. Solvent molecular mass  \t\t[g/mol]\n" ;
    const long double mol_mass_solvent = get_mol_mass();

    std::cout << "3. Solute experimental density \t\t[g/cm3]\n" ;
    long double density_solute = get_exp_density();
    std::cout << "4. Solute molecular mass  \t\t[g/mol]\n" ;
    long double mol_mass_solute = get_mol_mass();

    std::cout << "\nStarting number density calculation\n" ;
    std::cout << "Your solvent number density is : \t" ;
    long double  number_density_solvent =get_number_density(density_solvent,mol_mass_solvent);
    std::cout << "Your solute number density is : \t" ;
    long double  number_density_solute =get_number_density(density_solute,mol_mass_solute);
    std::cout << "\nThe number density ratio (solvent/solute) is:  \t"  ;
    long double number_density_ratio = number_density_solvent/number_density_solute ;
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
    long double total_molecules= number_molecules_solute+number_molecules_solvent ;
    std::cout<< "Total number of molecules in the mixture is :\t" << total_molecules << '\n';
    std::cout<< "\nSolvent occupy :\t\t\t";
    long double volume_solvent = get_volume(number_molecules_solvent,number_density_solvent);
    std::cout<< volume_solvent << "\t[Ang3]\n";
    std::cout<< "Solvent cubic box length :\t\t";
    long double solvent_box_length ;
    solvent_box_length= std::cbrt(volume_solvent);
    std::cout<< solvent_box_length << "\t[Ang]\n";

    // This is the number of molecules of the mixture if all molecules were solvent
    // So one can obtain the new volumes, volumen mix
    long double mix_number_molecules; //
    mix_number_molecules = (number_molecules_solvent+(number_density_ratio*number_molecules_solute));
    std::cout<< "\nMixture occupy :\t\t\t";
    long double volume_mix = get_volume(mix_number_molecules,number_density_solvent);
    std::cout<< volume_mix << "\t[Ang3]\n";
    std::cout<< "Mixture cubic box length :\t\t";
    long double mix_box_length ;
    mix_box_length= std::cbrt(volume_mix);
    std::cout<< mix_box_length << "\t[Ang]\n";
    long double number_density_mix ;
    number_density_mix= total_molecules/(volume_mix);
    std::cout << "\nYour mixture number density is : \t" << number_density_mix << "\t[molecules/Ang3]\n" ;
    long double relative_mix_mol_mass ;
    relative_mix_mol_mass = ((number_molecules_solvent*mol_mass_solvent)+(number_molecules_solute*mol_mass_solute))/total_molecules;
    long double density_mix ;
    density_mix = ((number_density_mix*cc3_to_ang3*relative_mix_mol_mass)/(avogadro));
    std::cout << "Your mixture  density is : \t\t" << density_mix << "\t[g/cc3]\n" ;
    std::cout << "\t\t\t\t\tSayonara baby! \t\t\t\t\n" ;
    std::cout << "**************************************************************************************\n" ;
    std::cout << "**************************************************************************************\n" ;
    std::cout << "**************************************************************************************\n" ;


    return 0;

}

void header(){
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

long double get_exp_density(){
    std::cout << "Please provide the density: \t\t";
    long double density;
    std::cin >> density;
    std::cout << "\n";
    return density;
}

long double get_mol_mass(){
    std::cout << "Please provide the molecular mass: \t";
    long double mol_mass;
    std::cin >> mol_mass;
    std::cout << "\n";
    return mol_mass;
}

long double get_number_density(long double dens, long double mol_mass){
    long double num_density = (dens*avogadro)/(mol_mass*cc3_to_ang3);
    std::cout << num_density <<"\t[molecules/Ang3]\n";
    return num_density;
}

long double get_volume(long double num_molecules, long double density_number){
    long double volume= (num_molecules/density_number);
    return volume;
}
