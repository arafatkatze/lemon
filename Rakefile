require "bundler/gem_tasks"
require "rspec/core/rake_task"

RSpec::Core::RakeTask.new(:spec)

task :default => :spec
require "rake/extensiontask"

task :build => :compile

Rake::ExtensionTask.new("lemon") do |ext|
  ext.lib_dir = "lib/lemon"
end
