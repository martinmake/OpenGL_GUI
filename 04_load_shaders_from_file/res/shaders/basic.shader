#shader vertex
#version 130

in vec4 position;

void main()
{
       gl_Position = position;
}

#shader fragment
#version 130

void main()
{
       gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);
}
