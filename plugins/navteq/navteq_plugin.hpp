/*
 * navteq_plugin.hpp
 *
 *  Created on: 11.06.2015
 *      Author: philip
 */

#ifndef NAVTEQPLUGIN_HPP_
#define NAVTEQPLUGIN_HPP_

#include "../base_plugin.hpp"
#include "navteq_types.hpp"
#include <boost/filesystem/path.hpp>
#include <string>

class navteq_plugin : public base_plugin {
private:
  bool is_valid_format(std::string format);
  void recurse_dir(const boost::filesystem::path &dir);
  bool check_files(const boost::filesystem::path &dir);
  void write_output();
  void add_administrative_boundaries();
  void add_water();
  void add_landuse();

  std::vector<boost::filesystem::path> dirs;

public:
  navteq_plugin(const boost::filesystem::path &executable_path);
  virtual ~navteq_plugin();

  bool check_input(
      const boost::filesystem::path &input_path,
      const boost::filesystem::path &output_path = boost::filesystem::path());
  void execute();
};

#endif /* NAVTEQPLUGIN_HPP_ */
