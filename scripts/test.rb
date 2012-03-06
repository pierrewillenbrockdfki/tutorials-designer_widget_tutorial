#! /usr/bin/env ruby

require 'vizkit'

Orocos.initialize
Orocos.load_typekit "base"

class TestWidget < Qt::Widget
    #slots :change_label!
    
    def initialize
        puts "TestWidget constructor"
        super
        puts "Before loading UI"
        @window = Vizkit.load(File.join(File.dirname(__FILE__),'testwidget.ui'))
        #@but = Qt::PushButton.new("Change label!", self)
        #@but.show
        #@but.connect( SIGNAL :clicked ) { change_label! }
      
        @window.show
        puts "UI loaded"
        show
        change_label!
    end
    
    def change_label!
        #@window.mywidget.setLabelText("New Text :)")
      
        rbs = Types::Base::Samples::RigidBodyState.new
        rbs.position[0] = 4
        
        
        adapter = Vizkit::TypelibQtAdapter.new(@window.mywidget)
      
        # Set label text
        ret = nil
        realret = nil
        realret = adapter.call_qt_method("setPose", [rbs], ret)
        puts "realret: #{realret}"
        puts "ret: #{ret}"
        
#        # Get label text
#        ret = Data.new
#        realret = nil
#        realret = adapter.call_qt_method("getLabelText", [], ret)
#        puts "realret: #{realret}"
#        puts "ret: #{ret}"
#        
      
        
        #@window.mywidget.setPose(rbs)
    end
    
    def show
        @window.show
    end
    
end

tw = TestWidget.new
tw.show

Vizkit.exec