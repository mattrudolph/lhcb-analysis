
#include <iostream>
#include "bs2st2buk_rhomunu_loop.h"
#include "Utils.h"

#include "TFile.h"
#include "TTree.h"

int main(int argc, char * argv[]) {


  AnalysisBase::cmdParser parser(argc,argv);

  const char * infile = parser.getCmdOption("-i");
  if(!infile) {
    std::cerr << "No input file specified with -i" << std::endl;
    return 1;
  }
  const char * outfile = parser.getCmdOption("-o", "bs2st2buk_rhomunu.root");

  std::string dirs = parser.getCmdOption("-d", "Bs2st2BuK_RhoMuX_Tuple,Bs2st2BuKSS_RhoMuX_Tuple");
  std::vector<std::string> dirlist;
  std::string::size_type pos = dirs.find_first_of(",");
  while ( pos != std::string::npos ) {
    dirlist.push_back( dirs.substr(0,pos) );
    dirs = dirs.substr(pos+1);
    pos = dirs.find_first_of(",");
  }
  //now add the last one
  dirlist.push_back(dirs);
  std::cout << dirlist.size() << std::endl;

  TFile f(infile);
  TFile fout(outfile,"RECREATE");

  for( std::vector<std::string>::const_iterator it=dirlist.begin(); it != dirlist.end(); ++it ) {
    std::cout << "Run over " << *it << std::endl;


    TTree * tree = (TTree*) f.Get( ((*it)+"/DecayTree").c_str() );
    if (!tree) {
      std::cerr << "Missing tree " << ((*it)+"/DecayTree") << std::endl;
      continue;
    }

    bs2st_bu2rhomunu::bs2st2buk_rhomunu_loop l(tree,&fout, *it );
    int res = l.initialize();
    if(res) 
      return res;

    res = l.loop();
    if(res) 
      return res;
    
    res = l.finalize();
    if(res) 
      return res;
  }

  return 0;


}
