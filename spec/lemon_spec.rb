require 'spec_helper'

describe Lemon do
  it 'has a version number' do
    expect(Lemon::VERSION).not_to be nil
  end


	context 'ListGraph' do

		it 'creates a graph, adds 3 nodes and counts them' do
			g = Lemon::ListGraph.new
			3.times { g.addNode }
			expect(Lemon.countNodes g).to eq(3)
		end

	end
end
