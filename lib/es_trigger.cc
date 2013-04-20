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

/*
 * config.h is generated by configure.  It contains the results
 * of probing for features, options etc.  It should be the first
 * file included in your .cc file.
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <es/es_trigger.h>
#include <es/es_queue.h>
#include <gr_io_signature.h>
#include <stdio.h>

/*
 * Create a new instance of es_trigger and return
 * a boost shared_ptr.  This is effectively the public constructor.
 */
/*"es_trigger_sptr 
es_make_trigger (pmt_t arb, es_queue_sptr queue, int itemsize, std::string blkname)
{
  return es_trigger_sptr (new es_trigger (arb,queue,itemsize,blkname));
}*/

/*
 * Specify constraints on number of input and output streams.
 * This info is used to construct the input and output signatures
 * (2nd & 3rd args to gr_block's constructor).  The input and
 * output signatures are used by the runtime system to
 * check that a valid number and type of inputs and outputs
 * are connected to this block.  In this case, we accept
 * only 1 input and 1 output.
 */
es_trigger::es_trigger (pmt_t _arb, es_queue_sptr _queue, std::string blkname, gr_io_signature_sptr in_sig, gr_io_signature_sptr out_sig)
  : gr_sync_block (blkname.append("_trigger"),
		   in_sig,
		   out_sig),
    arb(_arb), event_queue(_queue), d_time(0), d_length(1), d_lookback(0)
{
    event_types.push_back( pmt_intern( "default_trigger_event" ) );
    event_queue->print();
    //printf("done printing evt queue\n");
}

es_trigger::~es_trigger ()
{
}

int 
es_trigger::work (int noutput_items,
			gr_vector_const_void_star &input_items,
			gr_vector_void_star &output_items)
{
    // never call the base class directly
    printf("es_trigger::work() accessed directly (should be derived instead!)\n");
    assert(0);
}

pmt_t es_trigger::event_type(int idx){
    assert(event_types.size()>idx); 
    return event_types[idx]; 
}

