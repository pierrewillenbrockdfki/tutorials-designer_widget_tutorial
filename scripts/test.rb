#! /usr/bin/env ruby

require 'vizkit'

Orocos.initialize
Orocos.load_typekit "base"

class TestWidget < Qt::Widget
    
    def initialize
        super
        @window = Vizkit.load(File.join(File.dirname(__FILE__),'testwidget.ui'))
        @window.but_set_pos.connect(SIGNAL('clicked()')) {change_label!}
        show     
    end
    
    def change_label!
        if(!@window.x_edit.text.empty? && !@window.y_edit.text.empty? && !@window.z_edit.text.empty?)
            rbs = Types::Base::Samples::RigidBodyState.new
            rbs.position[0] = Float(@window.x_edit.text)
            rbs.position[1] = Float(@window.y_edit.text)
            rbs.position[2] = Float(@window.z_edit.text)

            # Enable Qt slots with Typelib types as arguments
            @window.mywidget.extend QtTyplelibExtension
            
            # Send Typelib type :)
            @window.mywidget.setPose(rbs)
        end
        
    end
    
    def show
        @window.show
    end
    
end

tw = TestWidget.new
tw.show

Vizkit.exec