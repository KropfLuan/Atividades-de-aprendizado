create table cliente (
    id_cliente int not null,
    nome char(90) not null,
    CPF char(11) not null,
    telefone char(11) not null,
    email char(50) not null,
    data_nascimento date not null,
    primary key (id_cliente) 
);

create table curso (
    id_curso int not null,
    nome char(90) not null,
    carga_horaria int not null,
    descricao char(120) not null,
    primary key (id_curso)
);

create table inscricao (
    id_curso int not null,
    id_cliente int not null,
    data_inscricao date not null,
    data_cancelamento date null,
    primary key (id_curso, id_cliente),
    foreign key (id_cliente) references cliente(id_cliente),
    foreign key (id_curso) references curso(id_curso)
);