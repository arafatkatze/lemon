require 'spec_helper'

describe Lemon do
  it 'has a version number' do
    expect(Lemon::VERSION).not_to be nil
  end


	context 'ListGraph' do

		before :each do
			@g = Lemon::ListGraph.new
		end

		it 'adds nodes and properly counts them' do
			3.times { @g.addNode }
			expect(Lemon.countNodes @g).to eq(3)
		end

		it 'removes nodes and properly counts them' do
			i, j, k = @g.addNode, @g.addNode, @g.addNode
			expect(Lemon.countNodes @g).to eq(3)
			@g.erase j
			expect(Lemon.countNodes @g).to eq(2)
			@g.erase k
			expect(Lemon.countNodes @g).to eq(1)
			@g.erase i
			expect(Lemon.countNodes @g).to eq(0)
		end

		it 'clears itself' do
			3.times { @g.addNode }
			expect(Lemon.countNodes @g).to eq(3)
			@g.clear
			expect(Lemon.countNodes @g).to eq(0)
		end

	end
end
