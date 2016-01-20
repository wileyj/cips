Name:		cips
Version:	0.0.1
Release:	1.mtvi
Summary:  	Client/Server for DBA IP modifications	
License: 	GPLv2
Group: 		Utilities
BuildArch:	x86_64
Source0:	%{name}-%{version}.tar.gz
BuildRoot: 	%{_tmppath}/%{realname}-%{version}-%{release}-root-%(%{__id_u} -n)

%description 
An ssl-enabled client/server application allowing remote modification of NIC's on a host.

BuildRequires: gcc-c++, openssl-devel

%package server
Summary:  Client/Server for DBA IP modifications
Group:    Utilities	 

%description server
An ssl-enabled server application allowing remote modification of NIC's on a host. 

%package client
Summary:  Client/Server for DBA IP modifications
Group:    Utilities

%description client 
This package contains the client needed to send queries to the server. 


%prep

%setup -q -n %{name}-%{version}
%configure 
make %{?_smp_mflags}

%install
%{__rm} -rf %{buildroot}
%{__make} install DESTDIR="%{buildroot}"

%clean
%{__rm} -rf %{buildroot}

%post -p /sbin/ldconfig
%post server
/sbin/chkconfig --add cips
/sbin/chkconfig cips on
%postun -p /sbin/ldconfig
%postun  server
/sbin/chkconfig --del cips

%files server
%defattr(-, root, root, 0755)
%{_bindir}/cips

%files client
%defattr(-, root, root, 0755)
%{_bindir}/cipc


%changelog
* Fri Sep 13 2013 Jesse Wiley<jesse.wiley@viacom.com> - 0.0.1-1
- initial build.
