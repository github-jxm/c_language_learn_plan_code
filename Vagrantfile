# -*- mode: ruby -*-
# vi: set ft=ruby :

# All Vagrant configuration is done below. The "2" in Vagrant.configure
# configures the configuration version (we support older styles for
# backwards compatibility). Please don't change it unless you know what
# you're doing.
Vagrant.configure("2") do |config|
  # The most common configuration options are documented and commented below.
  # For a complete reference, please see the online documentation at
  # https://docs.vagrantup.com.

  # Every Vagrant development environment requires a box. You can search for
  # boxes at https://vagrantcloud.com/search.
  config.vm.box = "bionic-server-cloudimg-amd64"

  # The url from where the 'config.vm.box' box will be fetched if it
  # doesn't already exist on the user's system.
  config.vm.box_url = "https://mirrors.shu.edu.cn/ubuntu-cloud-images/bionic/20180802/bionic-server-cloudimg-amd64-vagrant.box"

  # Create a forwarded port mapping which allows access to a specific port
  # within the machine from a port on the host machine. In the example below,
  # accessing "localhost:8080" will access port 80 on the guest machine.
  # NOTE: This will enable public access to the opened port
  # config.vm.network "forwarded_port", guest: 80, host: 8080

  # Create a forwarded port mapping which allows access to a specific port
  # within the machine from a port on the host machine and only allow access
  # via 127.0.0.1 to disable public access
  # config.vm.network "forwarded_port", guest: 80, host: 8080, host_ip: "127.0.0.1"

  # Create a private network, which allows host-only access to the machine
  # using a specific IP.
  # config.vm.network "private_network", ip: "192.168.33.10"

  # Create a public network, which generally matched to bridged network.
  # Bridged networks make the machine appear as another physical device on
  # your network.
  # config.vm.network "public_network"

  # Share an additional folder to the guest VM. The first argument is
  # the path on the host to the actual folder. The second argument is
  # the path on the guest to mount the folder. And the optional third
  # argument is a set of non-required options.
  #config.vm.synced_folder "../data", "/vagrant_data"
  config.vm.synced_folder "~", "/mnt"

  # Provider-specific configuration so you can fine-tune various
  # backing providers for Vagrant. These expose provider-specific options.
  # Example for VirtualBox:
  #
  config.vm.provider "virtualbox" do |vb|
    # Display the VirtualBox GUI when booting the machine
    # vb.gui = true
  
    # Customize the amount of memory on the VM:
    vb.name = "c_language_learn_plan"
    vb.cpus = "4"
    vb.memory = "2048"
  end
  #
  # View the documentation for the provider you are using for more
  # information on available options.

  # Enable provisioning with a shell script. Additional provisioners such as
  # Puppet, Chef, Ansible, Salt, and Docker are also available. Please see the
  # documentation for more information about their specific syntax and use.
  config.vm.provision "shell", inline: <<-SHELL
     sed -i 's/archive.ubuntu.com/mirrors.aliyun.com/' /etc/apt/sources.list
     apt-get update

     ## vim  
     apt-get install -y vim
     su - vagrant -c "git clone --recursive  https://github.com/Jiangxumin/dotvim.git /home/vagrant/.vim"
     su - vagrant -c "ln -s /home/vagrant/.vim/vimrc /home/vagrant/.vimrc"
     ## install YCM  
     apt-get install -y build-essential cmake

     ## git
     apt-get install -y git
     su - vagrant -c "git config --global user.email 'cjiangxumin@gmail.com'"
     su - vagrant -c "git config --global user.name 'jiangxumin'"
     su - vagrant -c "git config --global core.editor vim"

     ##
     apt-get install -y g++-multilib libc6-dev-i386
    
   SHELL
end
