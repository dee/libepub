/*
Copyright (c) 2014, Richard Martin
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Richard Martin nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL RICHARD MARTIN BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "Epub.hpp"

#include <utility>

using std::move;

Epub::Epub(string _filename) : 
	filename(_filename), 
	file(_filename), 
	container(file.get_directory_path()) 
{

	for(auto rf : container.rootfiles) {
		
		OPF tmp(file.get_directory_path(), rf.full_path);
		
		opf_files.push_back(tmp);
		
	}
	
}

Epub::Epub(Epub const & cpy) : 
	filename(cpy.filename), 
	file(cpy.file), 
	container(cpy.container) 
{
	
}

Epub::Epub(Epub && mv)  : 
	filename (move(mv.filename)), 
	file(move(mv.file)), 
	container(move(mv.container))
{
	
}

Epub& Epub::operator =(const Epub& cpy) { 
	filename = cpy.filename;
	file = cpy.file;
	container = cpy.container;
	return *this; 
}

Epub& Epub::operator =(Epub && mv) { 
	filename = move(mv.filename); 
	file = move(mv.file);
	container = move(mv.container);
	return *this; 
}

Epub::~Epub() {
		file.cleanup();
}

