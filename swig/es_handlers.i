/* -*- c++ -*- */
/*
 * Copyright 2011 Free Software Foundation, Inc.
 * 
 * This file is part of gr-eventstream
 * 
 * gr-eventstream is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * gr-eventstream is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with gr-eventstream; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

%include <es_handler.i>
// %template(es_handler_sptr) boost::shared_ptr<es_handler>;

pmt_t pmt_float_vector( std::vector< float > vec );
pmt_t pmt_complex_vector( std::vector< gr_complex > vec );

pmt_t event_create_gen_vector_f ( unsigned long long time, pmt_t float_list );
pmt_t event_create_gen_vector_c ( unsigned long long time, pmt_t cpx_list );

class es_handler_insert_vector : public es_handler {
    public:
        es_handler_insert_vector();
        void handler( pmt_t msg, gr_vector_void_star buf );
};

%include <es_handler_print.h>
%include <es_handler_file.h>

es_handler_sptr es_make_handler_flowgraph(es_pyhandler_def* _pyhd, int pool_size);
class es_handler_flowgraph : public es_handler {
    public:
        es_handler_flowgraph( es_pyhandler_def* _pyhd, int pool_size );
        void handler( pmt_t msg, gr_vector_void_star buf );
};






