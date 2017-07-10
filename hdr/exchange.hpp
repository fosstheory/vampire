//------------------------------------------------------------------------------
//
//   This file is part of the VAMPIRE open source package under the
//   Free BSD licence (see licence file for details).
//
//   (c) Richard F L Evans 2017. All rights reserved.
//
//   Email: richard.evans@york.ac.uk
//
//------------------------------------------------------------------------------
//

#ifndef EXCHANGE_H_
#define EXCHANGE_H_

// C++ standard library headers
#include <string>

// Vampire headers
#include "create.hpp"
#include "exchange.hpp"

//--------------------------------------------------------------------------------
// Namespace for variables and functions for exchange module
//--------------------------------------------------------------------------------
namespace exchange{

   //-----------------------------------------------------------------------------
   // Function to initialise exchange module
   //-----------------------------------------------------------------------------
   void initialize(std::vector<std::vector <cs::neighbour_t> >& cneighbourlist);

   //-----------------------------------------------------------------------------
   // Function to set exchange type isotropic, vectorial or tensorial
   //-----------------------------------------------------------------------------
   unsigned int set_exchange_type(std::string exchange_type_string);

   //-----------------------------------------------------------------------------
   // Function to calculate exchange fields for spins between start and end index
   //-----------------------------------------------------------------------------
   void fields(const int start_index, // first atom for exchange interactions to be calculated
               const int end_index, // last +1 atom to be calculated
               const std::vector<int>& neighbour_list_start_index,
               const std::vector<int>& neighbour_list_end_index,
               const std::vector<int>& type_array, // type for atom
               const std::vector<int>& neighbour_list_array, // list of interactions between atoms
               const std::vector<int>& neighbour_interaction_type_array, // list of interaction type for each pair of atoms with value given in exchange list
               const std::vector <zval_t>& i_exchange_list, // list of isotropic exchange constants
               const std::vector <zvec_t>& v_exchange_list, // list of vectorial exchange constants
               const std::vector <zten_t>& t_exchange_list, // list of tensorial exchange constants
               const std::vector<double>& spin_array_x, // spin vectors for atoms
               const std::vector<double>& spin_array_y,
               const std::vector<double>& spin_array_z,
               std::vector<double>& field_array_x, // field vectors for atoms
               std::vector<double>& field_array_y,
               std::vector<double>& field_array_z);

   //---------------------------------------------------------------------------
   // Function to process input file parameters for exchange module
   //---------------------------------------------------------------------------
   bool match_input_parameter(std::string const key, std::string const word, std::string const value, std::string const unit, int const line);

   //---------------------------------------------------------------------------
   // Function to process material parameters
   //---------------------------------------------------------------------------
   bool match_material_parameter(std::string const word, std::string const value, std::string const unit, int const line, int const super_index, const int sub_index, const int max_materials = 100);

} // end of exchange namespace

#endif //EXCHANGE_H_
